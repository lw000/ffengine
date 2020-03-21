#pragma once

#include <string>
#include <functional>

typedef struct message {
	int mid;
	int sid;
	std::string msg;
} message_t, * messae_p;

using Functor = std::function<bool(message_t* t)>;

Functor checkMessage();