#pragma once

#include <iostream>

#include "Room.h"

namespace chat {

	int chat::Room::max_ID = 0;

	Room Room::operator=(Room room)
	{
		_ID = room._ID;
		_user_1_ID = room._user_1_ID;
		_user_2_ID = room._user_2_ID;
		_is_private = room._is_private;
		_message_ID = room._message_ID;

		return *this;
	}

}
