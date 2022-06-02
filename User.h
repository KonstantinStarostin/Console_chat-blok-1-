#pragma once
#include <string>
#include <vector>

// Contain information for one unique (by ID & name) user

namespace Chat {

	class User {
	public:
		User() : ID(-1), name(""), pass(""), is_reg(false) {};

		User(std::string _name, std::string _pass) : ID(max_ID + 1), name(_name), pass(_pass)
		{
			max_ID++;
			is_reg = true;
		}
		
		bool reg();

		bool set_name(const std::vector<Chat::User>* all_users);
		bool set_name(std::string _name, const std::vector<Chat::User>* all_users);

		bool set_pass();
		bool set_pass(std::string _pass);

		int         get_ID()   const { return ID; }
		std::string get_name() const { return name; }
		
		bool check_pass(std::string _pass) { return (_pass == pass ? true : false); }

		// block for testing
		/*void print_info();
		void print_ID();
		void print_name();
		void print_pass();*/
		//

		User operator=(User user);

	private:

		int         ID;
		std::string name;
		std::string pass;
		bool        is_reg;

		// counter for all users in chat
		static int  max_ID;
	};

	// auxiliary function to work with name & password
	bool uniq_user_name(std::string str, const std::vector<Chat::User>* all_users);
	bool user_name_valid(std::string str);
	void user_name_req();

	bool user_pass_valid(std::string str);
	void user_pass_req();

}

