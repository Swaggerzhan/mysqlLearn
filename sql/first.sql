CREATE TABLE IF NOT EXISTS mytbl
(
    name    CHAR(20),
    birth   DATE NOT NULL,
    weight  INT,
    sex     ENUM('F', 'M')
) ENGINE = Innodb;