# Mysql学习笔记

### 关于表

* 创建表
    
    ```sql
        CREATE TABLE mytbl
        (
            name    CHAR(20),
            birth   DATE NOT NULL,
            weight  INT,
            sex     ENUM('F', 'M')
        ) ENGINE = Innodb;
    ```
如果需要创建不存在的表可以在开头加上 CREATE TABLE IF NOT EXISTS的语句，
这样在进行创建的时候如果表已经存在也不会发生错误。

使用 __CREATE TEMPORARY TABLE tbl_name__ 可以创建一个临时表，如果会话结束，将删除由TEMPORARY创建的表，使用TEMPORARY创建的表将只有创建者会话可见。

使用 __CREATE TABLE (新的表) LIKE (老的表)__ 可以创建一个相似的表结构，包括索引都会被复制，但数据不会被复制。 如果需要将老的表中数据填入新表中，可以使用 __INSERT INTO (新的表) SELECT * FROM (老的表)__ ，当前也可以加上 __WHERE__ 语句来进行条件筛选。

* 删除表

删除表就简单非常多

```sql
DROP TABLE table_name1, table_name2, ....; // 正常删除表
DROP TEMPORARY TABLE table_name1, table_name2, ....; // 删除临时表
DROP TABLE IF EXISTS table_name1, table_name2, ....; // 删除表，如果不存在也不报错
```





