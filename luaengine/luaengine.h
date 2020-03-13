#pragma once

#include "../common/service.h"

#ifdef __cplusplus
extern "C" {
#include "../lua/lua.h"
#include "../lua/lauxlib.h"
#include "../lua/lualib.h"
}

#endif // __cplusplus

#include <string>

class LuaEngine : public Service {
	lua_State* _L;

public:
	LuaEngine();
	~LuaEngine();

public:
	virtual bool init() override;
	virtual bool start() override;
	virtual void stop() override;

public:
	void addWorkDir(const std::string& workdir);

public:
	void addSerachPath(const std::string& path);
	void addSerachCPath(const std::string& path);

public:
	int executeScriptFromFile(const std::string& filename);
	int executeScriptGlobalFunction(const std::string& function);

public:
	void pushInteger(long long value);
	void pushString(const std::string& value);
	void pushBoolean(bool value);
	void pushNil();
};