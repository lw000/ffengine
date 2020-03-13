#include "object.h"

Object::Object() {

}

Object::~Object() {

}

void Object::setUserData(void* userData) {
	this->_userData = userData;
}

void* Object::getUserData() const {
	return this->_userData;
}

void Object::setUserTag(int tag) {
	this->_tag = tag;
}

int Object::getUserTag() const {
	return this->_tag;
}