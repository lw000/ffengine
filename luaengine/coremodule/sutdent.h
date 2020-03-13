#pragma once

#ifdef __cplusplus
extern "C" {
#include "../../lua/lua.h"
#include "../../lua/lauxlib.h"
#include "../../lua/lualib.h"
}
#endif

int luaopen_student_libs(lua_State* L);