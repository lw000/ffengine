#pragma once

#include <string>

class Object {
	void* _userData;
	int _tag;

public:
	Object();
	virtual ~Object();

public:
	Object(Object&) = delete;
	Object& operator=(const Object&) = delete;

public:
	void setUserData(void* userData);
	void* getUserData() const;

	void setUserTag(int tag);
	int getUserTag() const;

public:
	virtual std::string className() = 0;
};