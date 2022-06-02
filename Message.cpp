#pragma once

#include <iostream>

#include "Message.h"
#include "Interface.h"

namespace Chat {

	int Chat::Message::max_ID = 0;

	Message Message::operator=(Message msg)
	{
		ID = msg.ID;
		user_ID = msg.user_ID;
		text = msg.text;

		return *this;
	}
	
}
