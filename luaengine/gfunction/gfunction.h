#pragma once

#ifdef __cplusplus
extern "C" {
#include "../lua/lua.h"
#include "../lua/lauxlib.h"
#include "../lua/lualib.h"
}
#endif

int register_global_all(lua_State* L);