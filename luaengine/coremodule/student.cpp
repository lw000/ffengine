#include "sutdent.h"
#include <string>

class Student {
public:
	long long num;
	long long sex;
	long long age;
	std::string name;

public:
	Student();
	~Student();
};

Student::Student() : num(0), age(0), sex(0) {

}

Student::~Student() {

}

static int lnew(lua_State* L) {
	Student** s = (Student**)lua_newuserdata(L, sizeof(Student*));
	if (s == nullptr)
	{
		return 0;
	}
	*s = new Student();
	luaL_setmetatable(L, "student");
	return 1;
}

static int lset(lua_State* L) {
	int argc = lua_gettop(L);
	if (argc < 5)
	{
		return 0;
	}
	Student ** s = (Student**)luaL_checkudata(L, 1, "student");
	luaL_argcheck(L, s != NULL, 1, "invalid user data");
	if (s == NULL)
	{
		return 0;
	}
	(*s)->name = luaL_checkstring(L, 2);
	(*s)->num = luaL_checkinteger(L, 3);
	(*s)->age = luaL_checkinteger(L, 4);
	(*s)->sex = luaL_checkinteger(L, 5);
	return 0;
}

static int lget(lua_State* L) {
	Student** s = (Student**)luaL_checkudata(L, 1, "student");
	luaL_argcheck(L, s != NULL, 1, "invalid user data");
	if (s == NULL)
	{
		return 0;
	}
	lua_pushstring(L, (*s)->name.c_str());
	lua_pushinteger(L, (*s)->num);
	lua_pushinteger(L, (*s)->age);
	lua_pushinteger(L, (*s)->sex);
	return 4;
}

static int ltostring(lua_State* L) {
	Student** s = (Student**)luaL_checkudata(L, 1, "student");
	luaL_argcheck(L, s != NULL, 1, "invalid user data");
	if (s == NULL)
	{
		lua_pushstring(L, "");
		return 1;
	}

	lua_pushfstring(L, "name:%s num:%d age:%d sex:%d", (*s)->name.c_str(), (*s)->num, (*s)->age, (*s)->sex);
	return 1;
}

static int lgc(lua_State* L) {
	Student** s = (Student**)luaL_checkudata(L, 1, "student");
	luaL_argcheck(L, s != NULL, 1, "invalid user data");

	if (s)
	{
		delete (*s);
	}

	return 0;
}

const luaL_Reg lua_reg_student_member_funcs[] = {
	{"set", lset },
	{"get", lget },
	{"__tostring", ltostring},
	{"__gc", lgc},
	{NULL, NULL},
};

const luaL_Reg lua_reg_student_constructor_funcs[] = {
	{"new", lnew },
	{NULL, NULL},
};

int luaopen_student_libs(lua_State* L) {
	luaL_newmetatable(L, "student");
	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "__index");
	luaL_setfuncs(L, lua_reg_student_member_funcs, 0);
	luaL_newlib(L, lua_reg_student_constructor_funcs);

	return 1;
}