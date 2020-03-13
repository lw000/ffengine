// ffengine.cpp: 定义应用程序的入口点。
//

#include "ffengine.h"
#include "../logger/logger.h"
#include "../network/network.h"
#include "../luaengine/luaengine.h"

Network network;
LuaEngine engine;
Logger logger;

int main()
{
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
