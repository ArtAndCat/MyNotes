


MySQL 提供了丰富的字段类型，主要分为以下几大类：

## 1. 数值类型

### 整数类型
- **TINYINT**：1字节，范围：-128 到 127 或 0 到 255
- **SMALLINT**：2字节，范围：-32768 到 32767
- **MEDIUMINT**：3字节，范围：-8388608 到 8388607
- **INT / INTEGER**：4字节，范围：-2147483648 到 2147483647
- **BIGINT**：8字节，范围：-2^63 到 2^63-1

### 浮点数类型
- **FLOAT**：单精度浮点数，4字节
- **DOUBLE**：双精度浮点数，8字节
- **DECIMAL**：精确小数，用于存储精确的数值，如金额

## 2. 字符串类型

### 短字符串
- **CHAR**：定长字符串，0-255字符
- **VARCHAR**：变长字符串，0-65535字符

### 文本类型
- **TINYTEXT**：最大长度 255 字符
- **TEXT**：最大长度 65535 字符
- **MEDIUMTEXT**：最大长度 16777215 字符
- **LONGTEXT**：最大长度 4294967295 字符

### 二进制数据
- **BINARY**：定长二进制字符串
- **VARBINARY**：变长二进制字符串
- **BLOB**：二进制大对象
  - TINYBLOB
  - BLOB
  - MEDIUMBLOB
  - LONGBLOB

## 3. 日期和时间类型

- **DATE**：日期，格式：'YYYY-MM-DD'
- **TIME**：时间，格式：'HH:MM:SS'
- **DATETIME**：日期时间，格式：'YYYY-MM-DD HH:MM:SS'
- **TIMESTAMP**：时间戳，范围：1970-01-01 到 2038年
- **YEAR**：年份，范围：1901 到 2155

## 4. 其他类型

- **ENUM**：枚举类型，从预定义值列表中选择
- **SET**：集合类型，从预定义值集合中选择多个值
- **JSON**：JSON 数据类型（MySQL 5.7.8+）
- **BOOLEAN/BOOL**：布尔类型，实际上是 TINYINT(1) 的别名

## 示例用法

```sql
-- 创建表时使用不同的字段类型
CREATE TABLE users (
    id INT PRIMARY KEY AUTO_INCREMENT,
    username VARCHAR(50) NOT NULL,
    age TINYINT UNSIGNED,
    salary DECIMAL(10,2),
    email VARCHAR(100),
    birth_date DATE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    is_active BOOLEAN DEFAULT TRUE,
    preferences JSON
);

CREATE TABLE products (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    description TEXT,
    price DECIMAL(8,2),
    status ENUM('active', 'inactive', 'pending'),
    tags SET('new', 'hot', 'sale', 'featured')
);
```

## 选择字段类型的建议

1. **整数类型**：根据数据范围选择最小的合适类型
2. **字符串类型**：VARCHAR 比 CHAR 更节省空间
3. **金额数据**：使用 DECIMAL 避免浮点数精度问题
4. **时间数据**：根据精度需求选择 DATETIME 或 TIMESTAMP
5. **大文本**：使用 TEXT 类型替代 VARCHAR

选择合适的字段类型对数据库性能和存储效率至关重要。