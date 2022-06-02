#pragma once

#include <string>
#include <vector>

#include "User.h"
#include "Message.h"

// Contain one private (for two users) or public (for all users) chat room
// users ID (for private room, 0 - for public room)
// infomation (vector<int> message_ID) for all messages in this room

namespace Chat {

	class Room {
	public:

		Room() : ID(0), user_1_ID(0), user_2_ID(0), is_private(false) {}

		Room(int _user_1_ID, int _user_2_ID, bool _is_private) : ID(max_ID + 1), user_1_ID(_user_1_ID), user_2_ID(_user_2_ID), is_private(_is_private)
		{
			max_ID++;
		}

		int               get_ID()         const { return ID; };
		int               get_user_1_ID()  const { return user_1_ID; };
		int               get_user_2_ID()  const { return user_2_ID; };
		std::vector<int>  get_message_ID() const { return message_ID; };
		bool              get_private()    const { return is_private; };


		void add_message_ID(int ID) { message_ID.push_back(ID); }

		Room operator=(Room room);

	private:

		int   ID;
		int   user_1_ID; // 0 to public room
		int   user_2_ID; // 0 to public room
		bool  is_private;
		
		std::vector<int> message_ID;

		// counter for all rooms in chat
		static int max_ID;

	};

}
