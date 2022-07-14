#pragma once

#include <string>
#include <vector>

#include "User.h"
#include "Message.h"

// Contain one private (for two users) or public (for all users) chat room
// users ID (for private room, 0 - for public room)
// infomation (vector<int> message_ID) for all messages in this room

namespace chat {

	class Room {
	public:

		Room() : _ID(0), _user_1_ID(0), _user_2_ID(0), _is_private(false) {}

		Room(int user_1_ID, int user_2_ID, bool is_private) : _ID(max_ID + 1), _user_1_ID(user_1_ID), _user_2_ID(user_2_ID), _is_private(is_private)
		{
			max_ID++;
		}

		int               get_ID()         const { return _ID; };
		int               get_user_1_ID()  const { return _user_1_ID; };
		int               get_user_2_ID()  const { return _user_2_ID; };
		std::vector<int>  get_message_ID() const { return _message_ID; };
		bool              get_private()    const { return _is_private; };


		void add_message_ID(int ID) { _message_ID.push_back(ID); }

		Room operator=(Room room);

	private:

		int   _ID;
		int   _user_1_ID; // 0 to public room
		int   _user_2_ID; // 0 to public room
		bool  _is_private;
		
		std::vector<int> _message_ID;

		// counter for all rooms in chat
		static int max_ID;

	};

}

