//
// Created by Swagger on 2021/8/1.
//

#ifndef MYSQLLEARN_REDIS_H
#define MYSQLLEARN_REDIS_H

#include <iostream>
#include <string>

struct redisContext;


class RedisAPI{


public:

    RedisAPI(std::string address, int port);
    ~RedisAPI();

    /**
     *  通过key获取字符串，无则返回空字符串
     **/
    std::string get(std::string key);

    /**
     *  hash的get方法
     *  通过key获取字符串，无则返回空字符串
     **/
    std::string hget(std::string hashName, std::string key);

    /**
     *  设置Redis的key-value，失败返回false
     **/
    bool set(std::string key, std::string value);

    /**
     *  hash的set方法
     *  设置Redis的key-value，失败返回false
     **/
    bool hset(std::string hashName, std::string key, std::string value);





private:

    redisContext* redis_;           // redis上下文
    std::string address_;
    int port_;


};











#endif //MYSQLLEARN_REDIS_H
