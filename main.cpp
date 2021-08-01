#include <iostream>
#include "RedisAPI/include/Redis.h"

using std::cerr;
using std::endl;
using std::cout;
using std::string;
using std::to_string;

int main() {

    RedisAPI* redis = new RedisAPI("127.0.0.1", 6379);
    string hashName = "testHash";
    string key = "key";
    string value = "value";
    clock_t start = clock();
    for (int i=0; i<10000; i ++){
        string index = to_string(i);
        redis->hset(hashName, key + index, value + index);
    }

    for (int i=0; i<10000; i ++){
        string index = to_string(i);
        redis->hget(hashName, key + index);
    }


    clock_t end = clock();

    clock_t usedTime = end - start;
    cout << usedTime << endl;

    delete redis;

}
