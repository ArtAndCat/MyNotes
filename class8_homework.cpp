#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

#include <stdlib.h>
#include <stdbool.h>

// Linux/macOS需要的头文件
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

/*
 * 这个代码就是个💩 3天用deepseek赶工写出来的 拼好码 很多功能不完善
 * 比如:
 * 1.  订单无法删除
 * 2.  商品数据数量是固定的 有多个函数内部使用的固定数值 要想添加一个商品还需要
 *     修改多个函数 (我知道可以用#define 并且deepseek给的代码扩展性不错)
 * 3.  要想再添加一个价格需要修改多个函数(主要是显示相关的函数)
 * 4.  没做添加货物的按钮 也就是说仓库没法加 像个封死的自动售货机 卖完就死了
 * 5.  没做数据保存和读取(我学的C++的文件读取 我不知道和C也不一样)
 * 6.  代码优化  代码复用性差点  (生成表格部分做了三个内容80%内容重复的函数
 *     (打印表格  打印表格-0不输出  打印表格-0不输出-按照数量排序))
 * 7.  "生成订单"点击"确定"后就不能反悔
 * 8.  部分自己修改过的/自己写的变量名/函数名名称不规范
 * 9.  windows系统没有进行过测试
 * 10. 暂时想不到了
 *
 *
 *
 *
 *
 *
 *
 */

// 定义商品结构体
typedef struct
{
    int id;        // 编号
    char name[50]; // 名称
    int quantity;  // 剩余数量
    int price;     // 价格
} Item;

typedef struct
{
    int id;          // 编号
    char name[50];   // 名称
    Item User[6] = { // 所有
        {101, "能吃的", 0, 0},
        {102, "不能吃的", 0, 0},
        {103, "好吃的", 0, 0},
        {104, "不好吃的", 0, 0},
        {105, "吃了肚子疼的", 0, 0},
        {106, "吃了会死的", 0, 0}};

} UserItems;

// 更完整的UTF-8显示宽度计算
int get_display_width(const char *str)
{
    if (!str)
        return 0;

    int width = 0;
    unsigned char *p = (unsigned char *)str;

    while (*p)
    {
        // ASCII字符
        if (*p < 128)
        {
            width += 1;
            p++;
        }
        // 2字节UTF-8
        else if ((*p & 0xE0) == 0xC0)
        {
            width += 1; // 或2，根据实际需求
            p += 2;
        }
        // 3字节UTF-8（包括大部分中文）
        else if ((*p & 0xF0) == 0xE0)
        {
            width += 2;
            p += 3;
        }
        // 4字节UTF-8（如emoji）
        else if ((*p & 0xF8) == 0xF0)
        {
            width += 2; // emoji通常计2宽度
            p += 4;
        }
        // 无效UTF-8，按单字节处理
        else
        {
            width += 1;
            p++;
        }
    }
    return width;
}
// 打印指定数量的字符
void print_chars(char ch, int count)
{
    for (int i = 0; i < count; i++)
    {
        putchar(ch);
    }
}

// 打印分隔线
void print_separator(int id_width, int name_width, int qty_width)
{
    printf("+");
    print_chars('-', id_width + 2);
    printf("+");
    print_chars('-', name_width + 2);
    printf("+");
    print_chars('-', qty_width + 2);
    printf("+\n");
}
// 打印头
void print_header(int id_width, int name_width, int qty_width)
{
    print_separator(id_width, name_width, qty_width);

    // 表头文字的显示宽度
    int id_header_width = 4;   // "编号" 宽度为4 (2个中文字符 × 2)
    int name_header_width = 4; // "名称" 宽度为4 (2个中文字符 × 2)
    int qty_header_width = 4;  // "剩余" 宽度为4 (2个中文字符 × 2)

    // 打印"编号"列
    printf("| ");
    int id_padding_left = (id_width - id_header_width) / 2;
    int id_padding_right = id_width - id_header_width - id_padding_left;
    print_chars(' ', id_padding_left);
    printf("编号");
    print_chars(' ', id_padding_right);
    printf(" | ");

    // 打印"名称"列
    int name_padding_left = (name_width - name_header_width) / 2;
    int name_padding_right = name_width - name_header_width - name_padding_left;
    print_chars(' ', name_padding_left);
    printf("名称");
    print_chars(' ', name_padding_right);
    printf(" | ");

    // 打印"剩余数量"列 - 这里修复对齐问题
    int qty_padding_left = (qty_width - qty_header_width) / 2;
    int qty_padding_right = qty_width - qty_header_width - qty_padding_left;
    print_chars(' ', qty_padding_left);
    printf("数量");
    print_chars(' ', qty_padding_right);
    printf(" |\n");

    print_separator(id_width, name_width, qty_width);
}
// 打印英文表头
// void print_header_en(int id_width, int name_width, int qty_width)
// {
//     print_separator(id_width, name_width, qty_width);
//     printf("| %-*s | %-*s | %-*s |\n",
//            id_width, "ID",
//            name_width, "Name",
//            qty_width, "Quantity");
//     print_separator(id_width, name_width, qty_width);
// }

// 打印混合中英文的数据行
void print_mixed_row(int id, const char *name, int quantity,
                     int id_width, int name_width, int qty_width)
{
    printf("| %-*d | ", id_width, id);

    // 打印名称（处理中英文混合）
    if (name == NULL)
    {
        printf("%-*s | ", name_width, "NULL");
    }
    else
    {
        int name_len = strlen(name);
        int display_width = get_display_width(name);
        int padding = name_width - display_width;

        printf("%s", name);
        if (padding > 0)
        {
            print_chars(' ', padding);
        }
        printf(" | ");
    }

    printf("%-*d |\n", qty_width, quantity);
}

// 主要打印函数（支持中文）
void print_items_with_chinese(Item *items, int count)
{
    if (items == NULL || count <= 0)
    {
        printf("没有数据可显示。\n");
        return;
    }

    // 计算各列的最大显示宽度
    int id_width = 4;   // "编号" 宽度
    int name_width = 4; // "名称" 宽度
    int qty_width = 10; // "剩余数量" 宽度

    for (int i = 0; i < count; i++)
    {
        // 计算ID宽度
        char id_str[20];
        sprintf(id_str, "%d", items[i].id);
        int current_id_len = strlen(id_str);
        if (current_id_len > id_width)
        {
            id_width = current_id_len;
        }

        // 计算名称显示宽度
        if (items[i].name != NULL)
        {
            int current_name_width = get_display_width(items[i].name);
            if (current_name_width > name_width)
            {
                name_width = current_name_width;
            }
        }

        // 计算数量宽度
        sprintf(id_str, "%d", items[i].quantity);
        current_id_len = strlen(id_str);
        if (current_id_len > qty_width)
        {
            qty_width = current_id_len;
        }
    }

    // 确保最小宽度
    if (id_width < 4)
        id_width = 4;
    if (name_width < 4)
        name_width = 4;
    if (qty_width < 10)
        qty_width = 10;

    // 打印中文表头
    print_header(id_width, name_width, qty_width);

    // 打印数据行
    for (int i = 0; i < count; i++)
    {
        print_mixed_row(items[i].id, items[i].name, items[i].quantity,
                        id_width, name_width, qty_width);
    }

    // 打印底部边框
    print_separator(id_width, name_width, qty_width);

    // 打印统计信息
    printf("共 %d 行数据\n\n", count);
}

// 主要打印函数（仅显示有数据的）
void print_items_with_chinese_only(Item *items, int count)
{
    if (items == NULL || count <= 0)
    {
        printf("没有数据可显示。\n");
        return;
    }

    // 计算各列的最大显示宽度
    int id_width = 4;   // "编号" 宽度
    int name_width = 4; // "名称" 宽度
    int qty_width = 10; // "剩余数量" 宽度
    int m_width = 10;   // "剩余数量" 宽度

    for (int i = 0; i < count; i++)
    {
        // 计算ID宽度
        char id_str[20];
        sprintf(id_str, "%d", items[i].id);
        int current_id_len = strlen(id_str);
        if (current_id_len > id_width)
        {
            id_width = current_id_len;
        }

        // 计算名称显示宽度
        if (items[i].name != NULL)
        {
            int current_name_width = get_display_width(items[i].name);
            if (current_name_width > name_width)
            {
                name_width = current_name_width;
            }
        }

        // 计算数量宽度
        sprintf(id_str, "%d", items[i].quantity);
        current_id_len = strlen(id_str);
        if (current_id_len > qty_width)
        {
            qty_width = current_id_len;
        }
    }

    // 确保最小宽度
    if (id_width < 4)
        id_width = 4;
    if (name_width < 4)
        name_width = 4;
    if (qty_width < 10)
        qty_width = 10;

    // 打印中文表头
    print_header(id_width, name_width, qty_width);

    // 打印数据行
    for (int i = 0; i < count; i++)
    {
        if (items[i].quantity)
            print_mixed_row(items[i].id, items[i].name, items[i].quantity,
                            id_width, name_width, qty_width);
    }

    // 打印底部边框
    print_separator(id_width, name_width, qty_width);
}

// 主要打印函数（仅显示有数据的  并且排序）
void print_items_with_chinese_only_order(Item *items, int count)
{
    if (items == NULL || count <= 0)
    {
        printf("没有数据可显示。\n");
        return;
    }

    // 计算各列的最大显示宽度
    int id_width = 4;   // "编号" 宽度
    int name_width = 4; // "名称" 宽度
    int qty_width = 10; // "剩余数量" 宽度
    int m_width = 10;   // "剩余数量" 宽度

    for (int i = 0; i < count; i++)
    {
        // 计算ID宽度
        char id_str[20];
        sprintf(id_str, "%d", items[i].id);
        int current_id_len = strlen(id_str);
        if (current_id_len > id_width)
        {
            id_width = current_id_len;
        }

        // 计算名称显示宽度
        if (items[i].name != NULL)
        {
            int current_name_width = get_display_width(items[i].name);
            if (current_name_width > name_width)
            {
                name_width = current_name_width;
            }
        }

        // 计算数量宽度
        sprintf(id_str, "%d", items[i].quantity);
        current_id_len = strlen(id_str);
        if (current_id_len > qty_width)
        {
            qty_width = current_id_len;
        }
    }

    // 确保最小宽度
    if (id_width < 4)
        id_width = 4;
    if (name_width < 4)
        name_width = 4;
    if (qty_width < 10)
        qty_width = 10;

    // 打印中文表头
    print_header(id_width, name_width, qty_width);

    size_t order[6] = {0, 0, 0, 0, 0, 0};
    bool order_use[6] = {0, 0, 0, 0, 0, 0};

    for (size_t i = 0; i < count; i++)
    {
        size_t num = count;
        size_t maxnum = 0;
        for (size_t j = 0; j < count; j++)
        {
            if (maxnum <= items[j].quantity && !order_use[j])
            {
                num = j;
                maxnum = items[j].quantity;
            }
        }
        // if (num == count)
        // {
        //     for (size_t i = 0; i < count; i++)
        //     {
        //         if (!order_use)
        //         {
        //             /* code */
        //         }

        //     }

        // }

        order[i] = num;
        order_use[num] = true;
    }

    // 打印数据行
    for (int i = 0; i < count; i++)
    {
        if (items[order[i]].quantity)
            print_mixed_row(items[order[i]].id, items[order[i]].name, items[order[i]].quantity,
                            id_width, name_width, qty_width);
    }

    // 打印底部边框
    print_separator(id_width, name_width, qty_width);
}

// ++++++++++++++

Item items[] = {
    {100, "能吃的", 12, 0},
    {101, "不能吃的", 50, 0},
    {102, "好吃的", 15, 0},
    {103, "不好吃的", 20, 0},
    {104, "吃了肚子疼的", 98, 0},
    {105, "吃了会死的", 9, 0}};

Item User[] = { // 当前用户
    {100, "能吃的", 0, 0},
    {101, "不能吃的", 0, 0},
    {102, "好吃的", 0, 0},
    {103, "不好吃的", 0, 0},
    {104, "吃了肚子疼的", 0, 0},
    {105, "吃了会死的", 0, 0}};

Item allUser[] = { // 所有
    {100, "能吃的", 0, 0},
    {101, "不能吃的", 0, 0},
    {102, "好吃的", 0, 0},
    {103, "不好吃的", 0, 0},
    {104, "吃了肚子疼的", 0, 0},
    {105, "吃了会死的", 0, 0}};

UserItems userItems[50];
int userItemsId = 0; // id 到哪了

bool quit = false;
int choose = 0;
void chooseF()
{
    switch (choose)
    {
    case 0:
        printf(" 0 \n");
        break;
    case 1:
        printf(" 1 \n");
        break;

    default:
        break;
    }
}

// 定义菜单选项结构体
typedef struct
{
    char *text;     // 菜单项文本
    void (*func)(); // 菜单项对应的函数指针
} MenuItem;

// 全局变量
MenuItem *menu_items = NULL;
int menu_count = 0;
int current_selection = 0; // 当前选中的菜单项
int max_menu_items = 10;
char error[128] = "";
int Item_count = 6;
int current_action = 0;         // 当前选中的操作按钮
bool exit_program_flag = false; // 退出标志

// 清屏函数
void clear_screen()
{
    printf("\033[2J\033[H"); // ANSI escape codes for clearing screen
}

// 移动光标到指定位置
void move_cursor(int row, int col)
{
    printf("\033[%d;%dH", row, col);
}

// 设置文本颜色
void set_color(int color)
{
    printf("\033[%dm", color);
}

// 重置颜色和样式
void reset_style()
{
    printf("\033[0m");
}

// 简单的等待按键
void wait_for_key()
{
    printf("\n按回车继续...");
    getchar(); // 清除之前的换行符
}

// -------------------------------------------------------------------------------------------------------------------

// 定义操作按钮
typedef enum
{
    ACTION_BUY,     // 购入
    ACTION_RETURN,  // 放回
    ACTION_CONFIRM, // 确定
    ACTION_CANCEL,  // 取消
    ACTION_COUNT    // 操作数量
} ActionType;

// 打印分隔线
void print_separator(int id_width, int name_width, int qty_width, int price_width)
{
    printf("+");
    for (int i = 0; i < id_width + 2; i++)
        printf("-");
    printf("+");
    for (int i = 0; i < name_width + 2; i++)
        printf("-");
    printf("+");
    for (int i = 0; i < qty_width + 2; i++)
        printf("-");
    printf("+");
    for (int i = 0; i < price_width + 2; i++)
        printf("-");
    printf("+\n");
}
// 绘制完整界面
void draw_interface(Item *items, int count)
{
    clear_screen();

    // 计算各列宽度
    int id_width = 2;     // "ID"
    int name_width = 8;   // "商品名称"显示宽度为8
    int qty_width = 8;    // "库存数量"显示宽度为8
    int price_width = 10; // "购入"显示宽度为10（为了对齐）

    for (int i = 0; i < count; i++)
    {
        char temp[50];

        // ID宽度
        sprintf(temp, "%d", items[i].id);
        if (strlen(temp) > id_width)
            id_width = strlen(temp);

        // 名称宽度
        int name_disp_width = get_display_width(items[i].name);
        if (name_disp_width > name_width)
            name_width = name_disp_width;

        // 数量宽度
        sprintf(temp, "%d", items[i].quantity);
        if (strlen(temp) > qty_width)
            qty_width = strlen(temp);

        // 价格宽度 - 这里应该是用户的购买数量
        sprintf(temp, "%d", User[i].quantity);
        if (strlen(temp) > price_width)
            price_width = strlen(temp);
    }

    // 确保表头能放下（中文字符处理）
    if (id_width < 2)
        id_width = 2;
    if (name_width < 8)
        name_width = 8;
    if (qty_width < 8)
        qty_width = 8;
    if (price_width < 10)
        price_width = 10;

    // 计算表格总宽度
    int table_width = id_width + name_width + qty_width + price_width + 13; // 13个边框和分隔字符

    // 打印标题
    move_cursor(2, 5);
    set_color(36);
    printf("智能外卖订单系统-生成订单");
    reset_style();

    // 打印表头
    move_cursor(4, 5);
    print_separator(id_width, name_width, qty_width, price_width);

    move_cursor(5, 5);
    // 修正表头打印，确保中文字符正确对齐
    printf("| %-*s | ", id_width, "ID");

    // 打印"商品名称"
    printf("商品名称");
    int name_header_padding = name_width - 8; // "商品名称"显示宽度为8
    for (int i = 0; i < name_header_padding; i++)
        printf(" ");
    printf(" | ");

    // 打印"库存数量"
    printf("库存数量");
    int qty_header_padding = qty_width - 8; // "库存数量"显示宽度为8
    for (int i = 0; i < qty_header_padding; i++)
        printf(" ");
    printf(" | ");

    // 打印"购入"
    printf("购入");
    int price_header_padding = price_width - 4; // "购入"显示宽度为4
    for (int i = 0; i < price_header_padding; i++)
        printf(" ");
    printf(" |\n");

    move_cursor(6, 5);
    print_separator(id_width, name_width, qty_width, price_width);

    // 打印数据行
    for (int i = 0; i < count; i++)
    {
        move_cursor(7 + i, 5);

        if (i == current_selection)
        {
            // 选中的商品行 - 白底黑字
            set_color(107); // 白底
            set_color(30);  // 黑字

            printf("| %-*d | ", id_width, items[i].id);

            printf("%s", items[i].name);
            int name_padding = name_width - get_display_width(items[i].name);
            for (int j = 0; j < name_padding; j++)
                printf(" ");

            printf(" | %-*d | %-*d |",
                   qty_width, items[i].quantity,
                   price_width, User[i].quantity);

            reset_style();
        }
        else
        {
            printf("| %-*d | ", id_width, items[i].id);

            printf("%s", items[i].name);
            int name_padding = name_width - get_display_width(items[i].name);
            for (int j = 0; j < name_padding; j++)
                printf(" ");

            printf(" | %-*d | %-*d |",
                   qty_width, items[i].quantity,
                   price_width, User[i].quantity);
        }

        printf("\n");
    }

    // 打印数据行底部边框
    move_cursor(7 + count, 5);
    print_separator(id_width, name_width, qty_width, price_width);

    // ===== 按钮行（与表格合并）=====
    int button_row = 8 + count;

    // 按钮行内容
    move_cursor(button_row, 5);
    printf("|");

    // 按钮文本
    const char *button_texts[ACTION_COUNT] = {"购入", "放回", "确定", "取消"};

    // 计算按钮总显示宽度
    int button_total_width = 0;
    for (int i = 0; i < ACTION_COUNT; i++)
    {
        button_total_width += get_display_width(button_texts[i]) + 2; // 按钮+两边空格
        if (i < ACTION_COUNT - 1)
        {
            button_total_width += 3; // 按钮间距
        }
    }

    // 计算按钮在表格中的起始位置
    int button_start_pos = (table_width - button_total_width) / 2;

    // 填充按钮前的空格
    for (int i = 0; i < button_start_pos; i++)
    {
        printf(" ");
    }

    // 绘制按钮
    for (int i = 0; i < ACTION_COUNT; i++)
    {
        if (i == current_action)
        {
            // 选中的按钮 - 白底黑字
            set_color(107); // 白底
            set_color(30);  // 黑字
            printf(" %s ", button_texts[i]);
            reset_style();
        }
        else
        {
            // 普通按钮
            printf(" %s ", button_texts[i]);
        }

        // 按钮间距
        if (i < ACTION_COUNT - 1)
        {
            printf("   ");
        }
    }

    // 填充按钮后的空格
    int remaining_width = table_width - button_start_pos - button_total_width - 1;
    for (int i = 0; i < remaining_width; i++)
    {
        printf(" ");
    }
    printf("|\n");

    // 按钮行底部边框（与表格边框对齐）
    move_cursor(button_row + 1, 5);
    print_separator(id_width, name_width, qty_width, price_width);

    // ===== 简洁的提示信息 =====
    int hint_row = button_row + 3;
    move_cursor(hint_row, 5);
    set_color(90);

    const char *hint_text = "↑↓:选择商品 | ←→:选择操作 | Enter:执行";
    int hint_width = get_display_width(hint_text);
    int hint_start_pos = (table_width - hint_width) / 2;

    // 移动到提示信息的起始位置
    move_cursor(hint_row, 5 + hint_start_pos);
    printf("%s", hint_text);

    // 错误信息（如果有）
    if (error[0] != '\0')
    {
        move_cursor(hint_row + 1, 5);
        set_color(31);

        int error_width = get_display_width(error);
        int error_start_pos = (table_width - error_width) / 2;

        // 移动到错误信息的起始位置
        move_cursor(hint_row + 1, 5 + error_start_pos);
        printf("%s", error);
        error[0] = '\0'; // 清空错误信息
    }

    reset_style();
    fflush(stdout);
}
// 获取键盘输入
int get_key()
{
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    if (ch == 27)
    { // ESC
        ch = getchar();
        if (ch == 91)
        { // [
            ch = getchar();
            switch (ch)
            {
            case 65:
                ch = 'U';
                break; // 上
            case 66:
                ch = 'D';
                break; // 下
            case 67:
                ch = 'R';
                break; // 右
            case 68:
                ch = 'L';
                break; // 左
            }
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

// 处理购入操作
void handle_buy()
{
    if (items[current_selection].quantity)
    {
        --items[current_selection].quantity;
        ++User[current_selection].quantity;
    }
    else
    {
        // 错误
        strcpy(error, "错误-库存数量为0 请进货");
    }
    // clear_screen();
    // move_cursor(5, 20);
    // set_color(32);
    // printf("=== 购入商品 ===\n\n");
    // reset_style();

    // move_cursor(7, 15);
    // printf("当前商品: %s (ID: %d)",
    //        Items[current_selection].name,
    //        Items[current_selection].id);

    // move_cursor(9, 15);
    // printf("当前库存: %d", Items[current_selection].quantity);

    // move_cursor(11, 15);
    // printf("请输入购入数量: ");

    // int buy_quantity;
    // if (scanf("%d", &buy_quantity) == 1)
    // {
    //     if (buy_quantity > 0)
    //     {
    //         Items[current_selection].quantity += buy_quantity;

    //         move_cursor(13, 15);
    //         set_color(32);
    //         printf("✅ 购入成功！新库存: %d", Items[current_selection].quantity);
    //         reset_style();
    //     }
    //     else
    //     {
    //         move_cursor(13, 15);
    //         set_color(31);
    //         printf("❌ 无效的购入数量！");
    //         reset_style();
    //     }
    // }
    // else
    // {
    //     move_cursor(13, 15);
    //     set_color(31);
    //     printf("❌ 输入错误！");
    //     reset_style();
    //     while (getchar() != '\n')
    //         ; // 清除输入缓冲区
    // }

    // move_cursor(15, 15);
    // printf("按任意键继续...");
    // while (getchar() != '\n')
    //     ; // 清除输入缓冲区
    // getchar();
}

// 处理放回操作
void handle_return()
{
    if (User[current_selection].quantity)
    {
        ++items[current_selection].quantity;
        --User[current_selection].quantity;
    }
    else
    {
        // 错误
        strcpy(error, "错误-物品数量为0");
    }
    // clear_screen();
    // move_cursor(5, 20);
    // set_color(33);
    // printf("=== 放回商品 ===\n\n");
    // reset_style();

    // move_cursor(7, 15);
    // printf("当前商品: %s (ID: %d)",
    //        Items[current_selection].name,
    //        Items[current_selection].id);

    // move_cursor(9, 15);
    // printf("当前库存: %d", Items[current_selection].quantity);

    // move_cursor(11, 15);
    // printf("请输入放回数量: ");

    // int return_quantity;
    // if (scanf("%d", &return_quantity) == 1)
    // {
    //     if (return_quantity > 0 && return_quantity <= Items[current_selection].quantity)
    //     {
    //         Items[current_selection].quantity -= return_quantity;

    //         move_cursor(13, 15);
    //         set_color(33);
    //         printf("✅ 放回成功！新库存: %d", Items[current_selection].quantity);
    //         reset_style();
    //     }
    //     else
    //     {
    //         move_cursor(13, 15);
    //         set_color(31);
    //         printf("❌ 无效的放回数量！");
    //         reset_style();
    //     }
    // }
    // else
    // {
    //     move_cursor(13, 15);
    //     set_color(31);
    //     printf("❌ 输入错误！");
    //     reset_style();
    //     while (getchar() != '\n')
    //         ;
    // }

    // move_cursor(15, 15);
    // printf("按任意键继续...");
    // while (getchar() != '\n')
    //     ;
    // getchar();
}

// 处理确定操作
void handle_confirm()
{
    // 输入用户名
    char name[50];

    // 清屏并显示标题
    clear_screen();
    move_cursor(5, 20);
    set_color(34);
    printf("=== 订单确认 ===\n\n");
    reset_style();

    // 输入用户名
    move_cursor(7, 15);
    printf("请输入用户名: ");

    // 获取用户名输入
    fgets(name, sizeof(name), stdin);

    // 去掉末尾的换行符
    if (strlen(name) > 0 && name[strlen(name) - 1] == '\n')
    {
        name[strlen(name) - 1] = '\0';
    }

    // 如果用户名为空，设置为默认值
    if (strlen(name) == 0)
    {
        strcpy(name, "NULL");
    }

    // 生成...
    for (size_t i = 0; i < 6; i++)
    {
        allUser[i].quantity += User[i].quantity; // 添加到allUser
        userItems[userItemsId].User[i].quantity = User[i].quantity;
    }
    strcpy(userItems[userItemsId].name, name);
    userItems[userItemsId].id = ++userItemsId;
    // 清空列表 并且退出
    for (size_t i = 0; i < 6; i++)
    {
        User[i].quantity = 0;
    }
    exit_program_flag = true;
}

// 处理取消操作
void handle_cancel()
{
    // 清空列表 并且退出
    for (size_t i = 0; i < 6; i++)
    {
        items[i].quantity += User[i].quantity;
        User[i].quantity = 0;
    }
    exit_program_flag = true;
}

// 执行选中的操作
void execute_action()
{
    switch (current_action)
    {
    case ACTION_BUY:
        handle_buy();
        break;
    case ACTION_RETURN:
        handle_return();
        break;
    case ACTION_CONFIRM:
        handle_confirm();
        break;
    case ACTION_CANCEL:
        handle_cancel();
        break;
    }
}

// 主界面
void main_interface()
{
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);

    // 初始绘制
    draw_interface(items, 6);

    while (!exit_program_flag)
    {
        // 获取输入
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        int key = get_key();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 扩展-输入数字添加!!!!
        // 处理输入
        switch (key)
        {
        case 'U': // 上箭头 - 选择商品
            current_selection = (current_selection - 1 + Item_count) % Item_count;
            draw_interface(items, 6);
            break;

        case 'D': // 下箭头 - 选择商品
            current_selection = (current_selection + 1) % Item_count;
            draw_interface(items, 6);
            break;

        case 'L': // 左箭头 - 选择操作
            current_action = (current_action - 1 + ACTION_COUNT) % ACTION_COUNT;
            draw_interface(items, 6);
            break;

        case 'R': // 右箭头 - 选择操作
            current_action = (current_action + 1) % ACTION_COUNT;
            draw_interface(items, 6);
            break;

        case '\n': // Enter键 - 执行操作
            execute_action();
            draw_interface(items, 6);
            break;
        }
    }

    // 恢复终端设置
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

// 退出程序
void exit_program()
{
    clear_screen();
    move_cursor(10, 25);
    set_color(35);
    printf("感谢使用\n\n");
    reset_style();

    exit(0);
}

// --------------------------------------------------------------------------------------------------------------------

// 初始化菜单系统
void init_menu()
{
    menu_items = (MenuItem *)malloc(sizeof(MenuItem) * max_menu_items);
    if (menu_items == NULL)
    {
        printf("内存分配失败！\n");
        exit(1);
    }
    menu_count = 0;
    current_selection = 0;
}

// 添加菜单项
void add_menu_item(const char *text, void (*func)())
{
    if (menu_count >= max_menu_items)
    {
        // 扩展菜单数组
        max_menu_items *= 2;
        menu_items = (MenuItem *)realloc(menu_items, sizeof(MenuItem) * max_menu_items);
        if (menu_items == NULL)
        {
            printf("内存分配失败！\n");
            exit(1);
        }
    }

    menu_items[menu_count].text = strdup(text);
    menu_items[menu_count].func = func;
    menu_count++;
}

//  -  -  -  -  -  -  -  -  -  -  -  -  -  -

// 绘制菜单边框
void draw_box(int x, int y, int width, int height)
{
    int i, j;

    // 画上边框
    move_cursor(y, x);
    printf("+");
    for (i = 0; i < width - 2; i++)
        printf("-");
    printf("+");

    // 画中间部分
    for (j = 1; j < height - 1; j++)
    {
        move_cursor(y + j, x);
        printf("|");
        move_cursor(y + j, x + width - 1);
        printf("|");
    }

    // 画下边框
    move_cursor(y + height - 1, x);
    printf("+");
    for (i = 0; i < width - 2; i++)
        printf("-");
    printf("+");
}

// 绘制菜单
void draw_menu(int box_width = 50)
{
    clear_screen();

    // 菜单边框

    int box_height = menu_count + 6;
    int start_x = 10;
    int start_y = 3;

    draw_box(start_x, start_y, box_width, box_height);

    // 标题
    move_cursor(start_y + 1, start_x + 2);
    set_color(1); // 蓝色
    printf("智能外卖订单系统");
    reset_style();

    move_cursor(start_y + 2, start_x + 1);
    for (int i = 0; i < box_width - 2; i++)
        printf("-");

    // 菜单项
    for (int i = 0; i < menu_count; i++)
    {
        move_cursor(start_y + 3 + i, start_x + 3);

        if (i == current_selection)
        {
            set_color(7); // 反白显示
            printf("▶ ");
            set_color(7); // 白底黑字
            printf(" %s ", menu_items[i].text);
            reset_style();

            // 填充空格使背景完整
            int text_len = strlen(menu_items[i].text);
            for (int j = 0; j < box_width - 7 - text_len; j++)
                printf(" ");
        }
        else
        {
            printf("  %s", menu_items[i].text);
        }
    }

    // 底部提示
    move_cursor(start_y + box_height - 2, start_x + 2);
    set_color(33); //
    printf("使用 ↑ ↓ 方向键选择，Enter 确认 ");
    reset_style();

    // 刷新输出
    fflush(stdout);
}

// 获取单个字符输入（非阻塞）
int getch()
{
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

// ===== 示例功能函数 =====

void show_all_items()
{
    exit_program_flag = false;

    // 隐藏光标
    printf("\033[?25l");

    // 运行主界面
    main_interface();

    // 显示光标
    printf("\033[?25h");
}
void show_all_items2()
{
    if (userItemsId == 0)
    {
        clear_screen();
        move_cursor(10, 30);
        printf("暂无订单记录");
        wait_for_key();
        return;
    }

    // 自动跳转到最后一页（显示最新订单）
    int orders_per_page = 5; // 每页显示5个订单，因为每个订单要显示商品列表
    int total_pages = (userItemsId + orders_per_page - 1) / orders_per_page;
    int current_page = total_pages - 1; // 默认显示最后一页

    while (1)
    {
        clear_screen();

        // 标题
        move_cursor(2, 5);
        set_color(36);
        printf("# 订单历史记录");
        reset_style();

        move_cursor(3, 5);
        printf("共 %d 个订单 - 第 %d/%d 页\n", userItemsId, current_page + 1, total_pages);

        // 显示本页订单
        int start_idx = current_page * orders_per_page;
        int end_idx = (start_idx + orders_per_page < userItemsId)
                          ? start_idx + orders_per_page
                          : userItemsId;

        for (int i = start_idx; i < end_idx; i++)
        {

            set_color(33);
            printf("    ═ 订单 #%06d ════════════════════════════════\n", userItems[i].id);
            reset_style();
            printf("        用户: %s \n", userItems[i].name);
            printf("        商品清单:\n");
            print_items_with_chinese_only(userItems[i].User, 6);
        }

        // 底部导航
        printf("\n\n        ← → : 翻页 | Enter : 返回\n");
        reset_style();

        printf("        显示订单: %d-%d / %d", start_idx + 1, end_idx, userItemsId);

        // 获取输入
        int key = get_key();

        switch (key)
        {
        case 'L': // 左箭头 - 上一页
            if (current_page > 0)
            {
                current_page--;
            }
            break;

        case 'R': // 右箭头 - 下一页
            if (current_page < total_pages - 1)
            {
                current_page++;
            }
            break;

        case '\n': // Enter键 - 返回
            return;

        default:
            break;
        }
    }
}
void show_all_items3()
{
    clear_screen();
    move_cursor(2, 5);
    set_color(36);
    printf(" # 商品销量排序\n");
    reset_style();

    // 展示
    print_items_with_chinese_only_order(allUser, 6);

    wait_for_key();
}

// 初始化示例菜单  2.订单查询3.商品销量排序4.退出
void setup_example_menu()
{
    init_menu();
    //
    add_menu_item("生成订单", show_all_items);
    add_menu_item("订单查询", show_all_items2);
    add_menu_item("商品销量排序", show_all_items3);
    add_menu_item("退出程序", exit_program);
}

// 主函数
int main()
{
    // 设置终端为raw模式
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    setup_example_menu();

    while (1)
    {

        draw_menu();

        int key = get_key();

        switch (key)
        {
        case 'U': // 上箭头
            current_selection = (current_selection - 1 + menu_count) % menu_count;
            break;
        case 'D': // 下箭头
            current_selection = (current_selection + 1) % menu_count;
            break;
        case 10: // Enter键
        case 13: // 也是Enter键
            if (menu_items[current_selection].func != NULL)
            {
                // 恢复终端设置
                tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                menu_items[current_selection].func();
                // 重新设置raw模式
                tcsetattr(STDIN_FILENO, TCSANOW, &newt);
                current_selection = 0;
                current_action = 0;
            }
            break;
        }
    }

    // 恢复终端设置
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return 0;
}
