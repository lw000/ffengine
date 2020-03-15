// ffengine.cpp: 定义应用程序的入口点。
//

#include "ffengine.h"
#include "../logger/logger.h"
#include "../network/network.h"
#include "../luaengine/luaengine.h"

#include <functional>

Network network;
LuaEngine engine;
Logger logger;

//typedef std::function<void()> Functor;

using Functor = std::function<void()>;

Functor test(const std::string& v) {
	std::string s(v);
	return [=]() {
		std::cout << s << std::endl;
	};
}

#define EXEC_FUNCTOR(v) (test(v)())

int main()
{
	test("this is functor")();

	EXEC_FUNCTOR("this is functor");

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
