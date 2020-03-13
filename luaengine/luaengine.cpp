#include "luaengine.h"
#include "gfunction/gfunction.h"
#include "coremodule/module.h"

LuaEngine::LuaEngine() : _L(nullptr) {
	
}

LuaEngine::~LuaEngine() {

}

bool LuaEngine::init() {
	this->_L = luaL_newstate();
	return true;
}

bool LuaEngine::start() {
	bool ret = init();
	if (ret)
	{
		luaL_openlibs(this->_L);

		register_global_all(this->_L);
		register_module_all(this->_L);
	}
	return true;
}

void LuaEngine::stop() {
	lua_close(this->_L);
}

void LuaEngine::addWorkDir(const std::string& workdir) {
	lua_getglobal(this->_L, "package");
	lua_getfield(this->_L, -1, "path");
	const char* old_path = lua_tostring(this->_L, -1);
	std::string currentpath;
	currentpath.append(old_path);
	currentpath.append(";");
	currentpath.append(workdir);
	size_t pos = currentpath.find_last_of('\/');
	if (pos != std::string::npos)
	{
		currentpath.append("?.lua;");
	}
	else
	{
		currentpath.append("/?.lua;");
	}
	lua_pushstring(this->_L, currentpath.c_str());
	lua_setfield(this->_L, -3, "path");
	lua_pop(this->_L, 2);
}

void LuaEngine::addSerachPath(const std::string& path) {
	lua_getglobal(this->_L, "package");
	lua_getfield(this->_L, -1, "path");
	const char* old_path = lua_tostring(this->_L, -1);
	std::string currentpath;
	currentpath.append(old_path);
	currentpath.append(";");
	currentpath.append(path);
	lua_pushstring(this->_L, currentpath.c_str());
	lua_setfield(this->_L, -3, "path");
	lua_pop(this->_L, 2);
}

void LuaEngine::addSerachCPath(const std::string& cpath) {
	lua_getglobal(this->_L, "package");
	lua_getfield(this->_L, -1, "cpath");
	const char* old_cpath = lua_tostring(this->_L, -1);
	std::string currentcpath;
	currentcpath.append(old_cpath);
	currentcpath.append(";");
	currentcpath.append(cpath);
	lua_pushstring(this->_L, currentcpath.c_str());
	lua_setfield(this->_L, -3, "cpath");
	lua_pop(this->_L, 2);
}

int LuaEngine::executeScriptFromFile(const std::string& filename) {
	int ret = -1;

	do
	{
		ret = luaL_loadfile(this->_L, filename.c_str());
		if (ret != 0)
		{
			const char* errstr = lua_tostring(this->_L, -1);
			perror(errstr);
			break;
		}

		ret = lua_pcall(this->_L, 0, 0, 0);
		if (ret != 0)
		{
			const char* errstr = lua_tostring(this->_L, -1);
			perror(errstr);
			break;
		}

	} while (0);

	return ret;
}

int LuaEngine::executeScriptGlobalFunction(const std::string& function) {
	int ret = -1;
	do
	{
		lua_getglobal(this->_L, function.c_str());
		lua_pushinteger(this->_L, 100);
		lua_pushinteger(this->_L, 200);
		lua_pushstring(this->_L, "this is test message");
		ret =  lua_pcall(this->_L, 3, 1, 0);
		if (ret != 0)
		{
			const char* errstr = lua_tostring(this->_L, -1);
			perror(errstr);
			break;
		}

		long long result = lua_tointeger(this->_L, -1);
		if (result != 0)
		{
		}

		ret = 0;
	} while (0);

	return ret;
}

void LuaEngine::pushInteger(long long value) {
	lua_pushinteger(this->_L, value);
}

void LuaEngine::pushString(const std::string& value) {
	lua_pushstring(this->_L, value.c_str());
}

void LuaEngine::pushBoolean(bool value) {
	lua_pushboolean(this->_L, value);
}

void LuaEngine::pushNil() {
	lua_pushnil(this->_L);
}