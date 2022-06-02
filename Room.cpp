#pragma once

#include <iostream>

#include "Room.h"

namespace Chat {

	int Chat::Room::max_ID = 0;

	Room Room::operator=(Room room)
	{
		ID = room.ID;
		user_1_ID = room.user_1_ID;
		user_2_ID = room.user_2_ID;
		is_private = room.is_private;
		message_ID = room.message_ID;

		return *this;
	}

}
