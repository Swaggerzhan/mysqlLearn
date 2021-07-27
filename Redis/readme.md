# Redis 学习笔记

## Redis的配置，启动，操作，关闭等。

Redis安装后，会有一些可执行文件被安装到/usr/local/bin目录下。

```shell
redis-server        # 启动Redis
redis-cli           # 客户端
redis-benchmark     # Redis基准测试工具
redis-check-aof     # Redis AOF持久化文件检测和修复工具
redis-check-dump    # Redis RDB持久化文件检测和修复工具
redis-sentinel      # 启动 Redis Sentinel
```

#### 启动

建议使用一下方法启动Redis

```shell
redis-server 配置文件.conf
```

#### 客户端连接服务器

使用redis-cli客户端可以链接服务器

```shell
redis-cli -h 127.0.0.1 -p 6379
```

也可以直接在后面增加命令行来取数据，如: 

```shell
redis-cli -h 127.0.0.1 -p 6379 command
```

redis-cli客户端是默认认为连接的是127.0.0.1和6379上的server，如果不加-h和-p也是可以的。

#### 关闭

```shell
redis-cli shutdown # 关闭redis服务器
```

```shell
redis-cli shutdown nosave | save # 是否在关闭之前生成持久化文件
```

## Redis API

简单的命令

```shell
set 键 值    # 设置某个键 对应某个 值
get 键        # 获得某个键对应的值

keys *      # 遍历每个键，显示所有键，O(n)
dbsize       # 键总数 O(1)

exists 键    # 判断某个键是否存在，返回int类型的，1为存在
del 键       # 删除某个键，可以连续删除多个键

expire 键 时间 # 将某个键设置为过一段时间后过期，过期后将被自动删除
ttl 键       # 获得某个键还能存活多久 -1为改键永远存在，-2为键不存在，其他为剩余时间

type 键      # 获得某个键下的值所对应的类型
```

set指令有一些特殊选项，可以在设置键值的时候就设定选项

```shell
ex seconds: 为键设置秒级过期时间
```

##### Redis数据类型

type命令可以看到的数据类型是Redis想让看到的数据类型，内部还有很多编码用来实现这种`数据结构`。

##### 单线程架构

三个客户端同时发起执行命令

```shell
incr counter    # 客户端1
incr counter    # 客户端2
incr counter    # 客户端3
```

这些命令将同时发送到Redis服务器，不过执行指令将放到执行队列中去，具体执行顺序将有指令到达时间来决定(取决于网络延迟等)。







