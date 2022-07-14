#pragma once

#include <string>

// Contain one message (text) and information (user ID) about user which send this

namespace chat {

	class Message {
	public:
		Message() : _ID(-1), _user_ID(-1), _text("") {};

		Message(int user_ID, const std::string& text) : _ID(max_ID + 1), _user_ID(user_ID), _text(text)
		{
			max_ID++;
		};

		int         get_ID()      const { return _ID; }
		int         get_user_ID() const { return _user_ID; }
		std::string get_text()    const { return _text; }

		Message operator=(Message msg);

	private:

		int         _ID;
		int         _user_ID;
		std::string _text;

		// counter for all messages in chat
		static int  max_ID;
	};
}
