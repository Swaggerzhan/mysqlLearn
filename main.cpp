#include <iostream>
extern "C"{
#include "hiredis.h"
}

using std::cerr;
using std::endl;
using std::cout;

int main() {


    redisContext* redis = redisConnect("127.0.0.1", 6380);

    if ( redis == nullptr ){
        cerr << "connect to redis failed!" << endl;
        exit(1);
    }else {
        cout << "success" << endl;
    }

    void* ret = redisCommand(redis, "hget hash C++");
    redisReply* res = (redisReply*)ret;

    if ( res->type == REDIS_REPLY_STRING ){
        cout << "got String" << endl;
        cout << "res: " << res->str << endl;
    }


}
