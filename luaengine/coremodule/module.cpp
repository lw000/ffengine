#include "module.h"
#include "sutdent.h"

static const luaL_Reg lua_reg_libs[] = {
	{ "student", luaopen_student_libs},
	{ NULL, NULL }
};

int register_module_all(lua_State* L) {
	const luaL_Reg* lua_reg = lua_reg_libs;
	for (; lua_reg->func; ++lua_reg) {
		luaL_requiref(L, lua_reg->name, lua_reg->func, 1);
		lua_pop(L, 1);
	}
	return 1;
}