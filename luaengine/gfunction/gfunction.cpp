#include "gfunction.h"

int add(lua_State* L) {
	long long a = lua_tointeger(L, -2);
	long long b = lua_tointeger(L, -1);
	lua_pushinteger(L, a + b);
	return 1;
}

int register_global_all(lua_State* L) {
	lua_register(L, "cadd", add);
	return 1;
}