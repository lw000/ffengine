#include "hooks.h"

Functor checkMessage() {
	return {
		[](message_t* t) -> bool {
			return true;
		}
	};
}