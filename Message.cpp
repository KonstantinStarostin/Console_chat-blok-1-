#pragma once

#include <iostream>

#include "Message.h"
#include "Interface.h"

namespace chat {

	int chat::Message::max_ID = 0;

	Message Message::operator=(Message msg)
	{
		_ID = msg._ID;
		_user_ID = msg._user_ID;
		_text = msg._text;

		return *this;
	}
	
}
