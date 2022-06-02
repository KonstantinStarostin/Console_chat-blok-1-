#pragma once

#include <string>

// Contain one message (text) and information (user ID) about user which send this

namespace Chat {

	class Message {
	public:
		Message() : ID(-1), user_ID(-1), text("") {};

		Message(int _user_ID, std::string _text) : ID(max_ID + 1), user_ID(_user_ID), text(_text)
		{
			max_ID++;
		};

		int         get_ID()       { return ID; }
		int         get_user_ID()  { return user_ID; }
		std::string get_text()     { return text; }

		Message operator=(Message msg);

	private:

		int         ID;
		int         user_ID;
		std::string text;

		// counter for all messages in chat
		static int  max_ID;
	};
}
