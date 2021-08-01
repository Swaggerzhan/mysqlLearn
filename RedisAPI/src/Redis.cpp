//
// Created by Swagger on 2021/8/1.
//


#include "../include/Redis.h"
extern "C"{
#include "hiredis.h"
}


using std::cerr;
using std::cout;
using std::endl;
using std::string;

RedisAPI::RedisAPI(std::string address, int port)
:   address_(address),
    port_(port),
    redis_(nullptr)
{
    redis_ = redisConnect(address.c_str(), port);
    if ( !redis_ ){
        cerr << "redisConnect failed!" << endl;
        exit(1);
    }
    cout << "Redis Connect OK" << endl;

}


RedisAPI::~RedisAPI() {
    redisFree(redis_);
}

string RedisAPI::get(string key) {
    string retString;
    void* ret = redisCommand(redis_, "get %s", key.c_str());
    redisReply* res = (redisReply*)ret;
    if ( res->type == REDIS_REPLY_STRING ){
        cout << res->str << endl;
        retString = string(res->str, res->len);
    }else if ( res->type == REDIS_REPLY_INTEGER ){
        //retString = string(res->integer);
        cerr << "not finish yet" << endl;
    }
    freeReplyObject(ret);
    return retString;
}


string RedisAPI::hget(string hashName, string key) {
    void *ret = redisCommand(redis_, "hget %s %s", hashName.c_str(), key.c_str());
    redisReply* res = static_cast<redisReply*>(ret);
    string resString;
    if ( res->type == REDIS_REPLY_STRING ){
        resString = string(res->str, res->len);
    }


    return resString;

}


bool RedisAPI::set(string key, string value) {

    void *ret = redisCommand(redis_, "set %s %s", key.c_str(), value.c_str());
    freeReplyObject(ret);
    return true; // 如何判断错误?
}


bool RedisAPI::hset(std::string hashName, std::string key, std::string value) {
    void *ret = redisCommand(redis_, "hset %s %s %s",
                             hashName.c_str(), key.c_str(), value.c_str()
                             );
    freeReplyObject(ret);
    return true;
}











