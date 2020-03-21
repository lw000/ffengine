#include "hooks.h"
#include <iostream>

Functor checkMessage() {
	return {
		[](message_t* t) -> bool {
			std::cout << "mid=" << t->mid << "sid=" << t->sid << "msg=" << t->msg << std::endl;
			return true;
		}
	};
}