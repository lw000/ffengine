// ffengine.cpp: 定义应用程序的入口点。
//

#include "ffengine.h"
#include "../logger/logger.h"
#include "../network/network.h"
#include "../luaengine/luaengine.h"
#include "../libghttp/ghttp.h"
#include "../hooks/hooks.h"
#include <functional>
#include <string.h>

Network network;
LuaEngine engine;
Logger logger;

//typedef std::function<void()> Functor;

using Functor1 = std::function<void()>;

Functor1 test(const std::string& v) {
	std::string s(v);
	return [=]() {
		std::cout << s << std::endl;
	};
}

#define EXEC_FUNCTOR(v) (test(v)())

int test_http() {
    char* uri = "http://www.baidu.com";
    ghttp_request* request = NULL;
    ghttp_status status;
    FILE* pFile;
    char* buf;
    int bytes_read;
    int size;

    pFile = fopen("elesos.html", "wb");

    request = ghttp_request_new();
    if (ghttp_set_uri(request, uri) == -1)
        return -1;
    if (ghttp_set_type(request, ghttp_type_get) == -1)//get
        return -1;
    ghttp_prepare(request);
    status = ghttp_process(request);
    if (status == ghttp_error)
        return -1;
    printf("Status code -> %d\n", ghttp_status_code(request));
    buf = ghttp_get_body(request);

    bytes_read = ghttp_get_body_len(request);
    size = strlen(buf);//size == bytes_read
    fwrite(buf, 1, size, pFile);
    fclose(pFile);
}


int main()
{
	test("this is functor")();

	EXEC_FUNCTOR("this is functor");

    test_http();

    message_t t;
    t.mid = 100;
    t.sid = 100;
    t.msg = "123123123";
    checkMessage()(&t);

	logger.start();
	network.start();
	if (engine.start())
	{
		engine.addWorkDir("../../../../script/");
		engine.executeScriptFromFile("../../../../script/main.lua");
		engine.executeScriptGlobalFunction("server_init");
	}
	network.stop();
	engine.stop();
	logger.stop();

	return 0;
}
