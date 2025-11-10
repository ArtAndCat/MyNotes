#编程 #数据库 #视频笔记 #SQL

[网站笔记](https://jimhackking.github.io/%E8%BF%90%E7%BB%B4/MySQL%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0/#%E6%95%B0%E6%8D%AE%E7%B1%BB%E5%9E%8B)
视频：

 [[mysql字段类型]] [[数据类型]]

[[懒人数据库]]

[[语法]]
[[SQL安装]]
## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);text-align:center;"><font style="font-size:20px">MySQL概述  1~4</font></div> 


MySQL启动:  （旧）
```sql
# net start mysql80
```

```sql
# net stop mysql80
```
客户端连接    （旧）
```sql
自带的客户端命令行
# mysql 
```


启动 MySQL 服务  （arch linux）
```sql
sudo systemctl start mysqld
```

设置开机自动启动
```sql
sudo systemctl enable mysqld
```
进入sql
```sql
mysql -u root -p
```
#### 数据模型   04
---
客户端（多个）-SQL-> DBMS-> 数据库（多个）->表（多个）
## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);text-align:center;"><font style="font-size:20px">没想好写啥</font></div>
#### SQL通用语法  05
---
注释：
```sql
--或#开头  MySQL特有
/*
多行
*/
```
- 可以使用空格与缩进
- 不区分大小写   关键字建议使用大写
#### ==SQL语法的分类==   05
---
- DDL Data <font style="color:rgb(255,120,120)">Definition</font> Language  定义数据库对象（数据库，表，字段）
- DML ... <font style="color:rgb(150,250,150)">Manipulation</font>...   操作   增删改
- DQL  ... <font style="color:rgb(150,150,250)">Query</font>...   查询     查记录
- DCL  ... <font style="color:rgb(250,150,250)">Control</font>...  控制  创建数据库用户，控制数据库的访问权限
#### DDL Data <font style="color:rgb(255,100,100)">Definition</font> Language（数据定义）
---
数据定义语言


##### 数据库操作
查询所有数据库：
```SQL
SHOW DATABASES;
```
查找特定数据库
```sql
SHOW CREATE DATABASE 数据库名;
```
查询当前数据库：
```SQL
SELECT DATABASE();
```
创建数据库：
```SQL
CREATE DATABASE [ IF NOT EXISTS ] 数据库名[ DEFAULT CHARSET 字符集] [ COLLATE 排序规则 or 校对规则 ];
```
修改：
```sql
ALTER DATABASE 数据库名 [ [ DEFAULT ] CHARSET 字符集] [ COLLATE 排序规则 or 校对规则 ];
```
删除数据库：
```SQL
DROP DATABASE [ IF EXISTS ] 数据库名;
```
使用数据库：
```SQL
USE 数据库名;
```

注意事项：
- UTF8字符集长度为3字节，有些符号占4字节，所以推荐用utf8mb4字符集
##### 表操作
---查询当前数据库所有表：
```SQL
SHOW TABLES;
```
查询表结构：
```SQL
DESC 表名;
```
查询指定表的建表语句：
```SQL
SHOW CREATE TABLE 表名;
```

创建表： [[数据类型]]
```SQL
CREATE TABLE 表名(
	字段1 字段1类型 [COMMENT "字段1注释"] [NULL || NOT NULL] [约束],
	字段2 字段2类型 ... [约束],
	字段3 字段3类型 ... [约束],
	...
	字段n 字段n类型 ... [约束]
	[, PRIMARY KEY [索引名](字段1,字段x)]
)[ COMMENT "表注释" ];
```
最后一个字段后面没有逗号
==约束==
* PRIMARY KEY   定义主键（只能有一个）  不允许重复  不能为空 需要加 NOT  NULL
* UNIQUE    定义替代键  不允许重复    可以为空   但必须声明 NULL  或者 NOT  NULL

添加字段/==添加列==：
```SQL
ALTER TABLE 表名 ADD 字段名 类型(长度) [COMMENT 注释] [约束];
```
例：`ALTER TABLE emp ADD nickname varchar(20) COMMENT '昵称';`
约束
* DEFAULT  使用默认值
* CHECK 指定某一列可接受的值

创建一个和xx一样的表：
```sql
CREATE TABLE 表1 KIKE xx;
```
修改数据类型：
```SQL
ALTER TABLE 表名 MODIFY 字段名 新数据类型(长度);
```
修改字段名和字段类型：
```SQL
ALTER TABLE 表名 CHANGE 旧字段名 新字段名 类型(长度) [COMMENT 注释] [约束];
```
例：将`emp`表的`nickname`字段修改为`username`，类型为`varchar(30)`
`ALTER TABLE emp CHANGE nickname username varchar(30) COMMENT '昵称';`

删除字段：
```SQL
ALTER TABLE 表名 DROP 字段名;
```

修改表名：
```SQL
ALTER TABLE 表名 RENAME TO 新表名
```

删除表：
```SQL
DROP TABLE [IF EXISTS] 表名;
```
删除表，并重新创建该表：
```SQL
TRUNCATE TABLE 表名;
```

#### DML Data <font style="color:rgb(150,250,150)">Manipulation</font> Language（数据操作）
---
##### 添加数据
指定字段：
```SQL
INSERT INTO 表名 (字段名1, 字段名2, ...) VALUES (值1, 值2, ...);
```
全部字段：
```SQL
INSERT INTO 表名 VALUES (值1, 值2, ...);
```

批量添加数据：
```SQL
INSERT INTO 表名 (字段名1, 字段名2, ...) VALUES (值1, 值2, ...), (值1, 值2, ...), (值1, 值2, ...);

INSERT INTO 表名 VALUES (值1, 值2, ...), (值1, 值2, ...), (值1, 值2, ...);
```


注意事项：
- 字符串和日期类型数据应该包含在引号中
- 插入的数据大小应该在字段的规定范围内
##### 更新和删除数据
修改数据：
```SQL
UPDATE 表名 SET 字段名1 = 值1, 字段名2 = 值2, ... [ WHERE 条件 ];
```
例：`UPDATE emp SET name = 'Jack' WHERE id = 1;`

删除数据：
```SQL
DELETE FROM 表名 [ WHERE 条件 ];
```
例；`SELECT * FROM students WHERE city = '北京';`  查询
`DELETE FROM students WHERE city = '北京';` 删除
#### DQL Data <font style="color:rgb(150,150,250)">Query</font> Language（数据查询）
---
语法：
```SQL
SELECT
	字段列表
FROM
	表名字段
WHERE
	条件列表
GROUP BY
	分组字段列表
HAVING
	分组后的条件列表
ORDER BY
	排序字段列表
LIMIT
	分页参数
```


##### 基础查询
查询多个字段：
```SQL
SELECT 字段1, 字段2, 字段3, ... FROM 表名;
```
```SQL
SELECT * FROM 表名;
```

设置别名：
```SQL
SELECT 字段1 [ AS 别名1 ], 字段2 [ AS 别名2 ], 字段3 [ AS 别名3 ], ... FROM 表名;
```
```SQL
SELECT 字段1 [ 别名1 ], 字段2 [ 别名2 ], 字段3 [ 别名3 ], ... FROM 表名;
```

去除重复记录：
```SQL
SELECT DISTINCT 字段列表 FROM 表名;
```

转义：
```SQL
SELECT * FROM 表名 WHERE name LIKE '/_张三' ESCAPE '/'
```
/ 之后的_不作为通配符

##### 条件查询
语法：
```SQL
SELECT 字段列表 FROM 表名 WHERE 条件列表;
```

条件：

| 比较运算符           | 功能                      |
| --------------- | ----------------------- |
| >               | 大于                      |
| >=              | 大于等于                    |
| <               | 小于                      |
| <=              | 小于等于                    |
| =               | 等于                      |
| <> 或 !=         | 不等于                     |
| BETWEEN … AND … | 在某个范围内（含最小、最大值）         |
| IN(…)           | 在in之后的列表中的值，多选一         |
| LIKE 占位符        | 模糊匹配（\_匹配单个字符，%匹配任意个字符） |
| IS NULL         | 是NULL                   |

| 逻辑运算符           | 功能                      |
|--|--|
| AND 或 &&        | 并且（多个条件同时成立）            |
| OR 或 \|\|       | 或者（多个条件任意一个成立）          |
| NOT 或 !         | 非，不是                    |
例子：

```SQL
-- 年龄等于30
select * from employee where age = 30;
-- 年龄小于30
select * from employee where age < 30;
-- 小于等于
select * from employee where age <= 30;
-- 没有身份证
select * from employee where idcard is null or idcard = '';
-- 有身份证
select * from employee where idcard;
select * from employee where idcard is not null;
-- 不等于
select * from employee where age != 30;
-- 年龄在20到30之间
select * from employee where age between 20 and 30;
select * from employee where age >= 20 and age <= 30;
-- 下面语句不报错，但查不到任何信息
select * from employee where age between 30 and 20;
-- 性别为女且年龄小于30
select * from employee where age < 30 and gender = '女';
-- 年龄等于25或30或35
select * from employee where age = 25 or age = 30 or age = 35;
select * from employee where age in (25, 30, 35);
-- 姓名为两个字
select * from employee where name like '__';
-- 身份证最后为X
select * from employee where idcard like '%X';
```
##### 聚合查询（聚合函数）
常见聚合函数：

|函数	|功能|
|--|-|
|count	|统计数量|
|max	|最大值|
|min	|最小值|
|avg|平均值|
|sum	|求和|
语法：
```SQL
SELECT 聚合函数(字段列表) FROM 表名;
```
例：`SELECT count(id) from employee where workaddress = "广东省";`

##### 分组查询
语法：
```SQL
SELECT 字段列表 FROM 表名 [ WHERE 条件 ] GROUP BY 分组字段名 [ HAVING 分组后的过滤条件 ];
```

where 和 having 的区别：

- 执行时机不同：where是分组之前进行过滤，不满足where条件不参与分组；having是分组后对结果进行过滤。
- 判断条件不同：where不能对聚合函数进行判断，而having可以。
例子：

```SQL
-- 根据性别分组，统计男性和女性数量（只显示分组数量，不显示哪个是男哪个是女）
select count(*) from employee group by gender;
-- 根据性别分组，统计男性和女性数量
select gender, count(*) from employee group by gender;
-- 根据性别分组，统计男性和女性的平均年龄
select gender, avg(age) from employee group by gender;
-- 年龄小于45，并根据工作地址分组
select workaddress, count(*) from employee where age < 45 group by workaddress;
-- 年龄小于45，并根据工作地址分组，获取员工数量大于等于3的工作地址
select workaddress, count(*) address_count from employee where age < 45 group by workaddress having address_count >= 3;
```
注意事项
- 执行顺序：where > 聚合函数 > having
- 分组之后，查询的字段一般为聚合函数和分组字段，查询其他字段无任何意义

##### 排序查询
语法：
```SQL
SELECT 字段列表 FROM 表名 ORDER BY 字段1 排序方式1, 字段2 排序方式2;
```

排序方式：
- ASC: 升序（默认）
- DESC: 降序
例子：

```SQL
-- 根据年龄升序排序
SELECT * FROM employee ORDER BY age ASC;
SELECT * FROM employee ORDER BY age;
-- 两字段排序，根据年龄升序排序，入职时间降序排序
SELECT * FROM employee ORDER BY age ASC, entrydate DESC;
```
注意事项
- 如果是多字段排序，当第一个字段值相同时，才会根据第二个字段进行排序

##### 分页查询 
语法：
```SQL
SELECT 字段列表 FROM 表名 LIMIT 起始索引, 查询记录数;
```

例子：
```SQL
-- 查询第一页数据，展示10条
SELECT * FROM employee LIMIT 0, 10;
-- 查询第二页
SELECT * FROM employee LIMIT 10, 10;
```
注意事项
- 起始索引从0开始，起始索引 = （查询页码 - 1） * 每页显示记录数
- 分页查询是数据库的方言，不同数据库有不同实现，MySQL是LIMIT
- 如果查询的是第一页数据，起始索引可以省略，直接简写 LIMIT 10

##### DQL执行顺序：
<font style="color:rgb(250,200,200)">FROM</font> -> <font style="color:rgb(250,250,200)">WHERE</font> -> <font style="color:rgb(200,250,200)">GROUP BY</font> -> <font style="color:rgb(200,250,250)">SELECT</font> -> <font style="color:rgb(200,200,250)">ORDER BY</font> -> <font style="color:rgb(250,200,250)">LIMIT</font>

- **FROM**: 指定查询的表。
- **WHERE**: 过滤结果。
- **GROUP BY**: 对结果分组。
- **SELECT**: 选择要显示的列。
- **ORDER BY**: 排序结果。
- **LIMIT**: 限制结果行数。
#### DCL Data <font style="color:rgb(250,150,250)">Definition</font> Language （管理用户）
--- 
查询用户：

```SQL
USE mysql;
SELECT * FROM user;
```
创建用户:
```SQL
CREATE USER '用户名'@'主机名' IDENTIFIED BY '密码';
```

修改用户密码：
```SQL
ALTER USER '用户名'@'主机名' IDENTIFIED WITH mysql_native_password BY '新密码';
```

删除用户：
```SQL
DROP USER '用户名'@'主机名';
```

例子：

```SQL
-- 创建用户test，只能在当前主机localhost访问
create user 'test'@'localhost' identified by '123456';
-- 创建用户test，能在任意主机访问
create user 'test'@'%' identified by '123456';
create user 'test' identified by '123456';
-- 修改密码
alter user 'test'@'localhost' identified with mysql_native_password by '1234';
-- 删除用户
drop user 'test'@'localhost';
```
注意事项
- 主机名可以使用 % 通配
##### 权限控制
常用权限：

| 权限                  | 说明         |
| ------------------- | ---------- |
| ALL, ALL PRIVILEGES | 所有权限       |
| SELECT              | 查询数据       |
| INSERT              | 插入数据       |
| UPDATE              | 修改数据       |
| DELETE              | 删除数据       |
| ALTER               | 修改表        |
| DROP                | 删除数据库/表/视图 |
| CREATE              | 创建数据库/表    |
| 更多权限请看权限一览表         |            |


查询权限：
```SQL
SHOW GRANTS FOR '用户名'@'主机名';
```

授予权限：
```SQL
GRANT 权限列表 ON 数据库名.表名 TO '用户名'@'主机名';
```

撤销权限：
```SQL
REVOKE 权限列表 ON 数据库名.表名 FROM '用户名'@'主机名';
```

注意事项
- 多个权限用逗号分隔
- 授权时，数据库名和表名可以用 * 进行通配，代表所有
##### 函数
- 字符串函数
- 数值函数
- 日期函数
- 流程函数
- 字符串函数
常用函数：

|函数	|功能|
|--|-|
|CONCAT(s1, s2, …, sn)	|字符串拼接，将s1, s2, …, sn拼接成一个字符串|
|LOWER(str)	|将字符串全部转为小写|
|UPPER(str)	|将字符串全部转为大写|
|LPAD(str, n, pad)	|左填充，用字符串pad对str的左边进行填充，达到n个字符串长度|
|RPAD(str, n, pad)	|右填充，用字符串pad对str的右边进行填充，达到n个字符串长度|
|TRIM(str)	|去掉字符串头部和尾部的空格|
|SUBSTRING(str, start, len)	|返回从字符串str从start位置起的len个长度的字符串|
|REPLACE(column, source, replace)	|替换字符串|
使用示例：

```SQL
-- 拼接
SELECT CONCAT('Hello', 'World');
-- 小写
SELECT LOWER('Hello');
-- 大写
SELECT UPPER('Hello');
-- 左填充
SELECT LPAD('01', 5, '-');
-- 右填充
SELECT RPAD('01', 5, '-');
-- 去除空格
SELECT TRIM(' Hello World ');
-- 切片（起始索引为1）
SELECT SUBSTRING('Hello World', 1, 5);
```
##### 数值函数
常见函数：

|函数	|功能|
|-|-|
|CEIL(x)	|向上取整|
|FLOOR(x)	|向下取整|
|MOD(x, y)	|返回x/y的模|
|RAND()	|返回0~1内的随机数|
|ROUND(x, y)	|求参数x的四舍五入值，保留y位小数|
##### 日期函数
常用函数：

| 函数                                 | 功能                          |
| ---------------------------------- | --------------------------- |
| CURDATE()                          | 返回当前日期                      |
| CURTIME()                          | 返回当前时间                      |
| NOW()                              | 返回当前日期和时间                   |
| YEAR(date)                         | 获取指定date的年份                 |
| MONTH(date)                        | 获取指定date的月份                 |
| DAY(date)                          | 获取指定date的日期                 |
| DATE_ADD(date, INTERVAL expr type) | 返回一个日期/时间值加上一个时间间隔expr后的时间值 |
| DATEDIFF(date1, date2)             | 返回起始时间date1和结束时间date2之间的天数  |

例子：
```SQL
-- DATE_ADD
SELECT DATE_ADD(NOW(), INTERVAL 70 YEAR);
```


##### 流程函数
常用函数：

| 函数                                                               | 功能                                     |
| ---------------------------------------------------------------- | -------------------------------------- |
| IF(value, t, f)                                                  | 如果value为true，则返回t，否则返回f                |
| IFNULL(value1, value2)                                           | 如果value1不为空，返回value1，否则返回value2        |
| CASE WHEN [ val1 ] THEN [ res1 ] … ELSE [ default ] END          | 如果val1为true，返回res1，… 否则返回default默认值    |
| CASE [ expr ] WHEN [ val1 ] THEN [ res1 ] … ELSE [ default ] END | 如果expr的值等于val1，返回res1，… 否则返回default默认值 |
例子：
```SQL
select
	name,
	(case when age > 30 then '中年' else '青年' end)
from employee;
select
	name,
	(case workaddress when '北京市' then '一线城市' when '上海市' then '一线城市' else '二线城市' end) as '工作地址'
from employee;
```

##### 约束
分类：

| 约束   | 描述                           | 关键字         |
| ---- | ---------------------------- | ----------- |
| 非空约束 | 限制该字段的数据不能为null              | NOT NULL    |
| 唯一约束 | 保证该字段的所有数据都是唯一、不重复的          | UNIQUE      |
| 主键约束 | 主键是一行数据的唯一标识，要求非空且唯一         | PRIMARY KEY |
| 默认约束 | 保存数据时，如果未指定该字段的值，则采用默认值      | DEFAULT     |
| 检查约束 | （8.0.1版本后）	保证字段值满足某一个条件      | CHECK       |
| 外键约束 | 用来让两张图的数据之间建立连接，保证数据的一致性和完整性 | FOREIGN KEY |
|      |                              |             |


约束是作用于表中字段上的，可以再创建表/修改表的时候添加约束。

##### 常用约束  [web](https://jimhackking.github.io/%E8%BF%90%E7%BB%B4/MySQL%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0/#%E5%B8%B8%E7%94%A8%E7%BA%A6%E6%9D%9F)

|     |     |
| --- | --- |
|     |     |

约束条件	关键字
主键	PRIMARY KEY
自动增长	AUTO_INCREMENT
不为空	NOT NULL
唯一	UNIQUE
逻辑条件	CHECK
默认值	DEFAULT
例子：
```SQL
create table user(
	id int primary key auto_increment,
	name varchar(10) not null unique,
	age int check(age > 0 and age < 120),
	status char(1) default '1',
	gender char(1)
);
```












## 旧笔记

---
##### 查询：
查询所有数据库
```SQL
SHOW DATABASES;
```
查询当前数据库
```sql
SELECT DATABASE();
```
##### 创建：
```sql
CREATE DATABASE [IF NOT EXISTS ] 数据库名 [DEFAULT CHARSET 字符集][COLLATE 排序规则];
```
返回 Query OK 说明成功
第一个\[....\]表示如果已经有就不用创建了，这样就不会有报错
字符集：
- utf8mb4   4字节
- utf8           3字节
##### 删除：
```sql
DROP DATABASE[IF EXISTS]数据库名;
```
##### 使用数据库：
```sql
USE 数据库名;
```

#### DML    07    操作
---
查询当前数据库所有表：
```sql
SHOW TABLES;
```
查询表结构：
```sql
DESC 表名;
```
查询指定表的建表语句：
```sql
SHOW CREATE TABLE 表名;
```
#### DQL     08     查询
---
```

```
#### DCL     09    控制
---
```

```

## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);text-align:center;"><font style="font-size:20px">没想好写啥</font></div>


####
5
##### 记录操作：
###### 开始记录（需要告诉MySQL记录要保存到哪里）
Linux
```sql
TEE /run/media/art/text/MySql/MysqlTest.2077.11.22.log
```
windows
```sql
TEE D:\Mysql\MysqlTest.2077.11.22.log
```
###### 查看表结构（记录到文件）
```sql
DESC MyBooks1;
-- 或者使用完整命令
DESCRIBE MyBooks1;
-- 或者使用信息模式查询
SHOW COLUMNS FROM MyBooks1;
```
###### 取消记录
```sql
NOTEE
```
###### 永久设置
如果希望每次启动mysql客户端都自动记录，可以在`my.cnf`配置文件中添加：
```ini
[mysql]
tee=/path/to/mysql.log
```
或者在启动时指定：
```bash
mysql --tee=/path/to/mysql.log
```





