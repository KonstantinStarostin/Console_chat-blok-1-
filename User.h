#pragma once

#include <string>
#include <vector>

// Contain information for one unique (by ID & name) user

namespace chat {

	class User {
	public:
		
		User() : _ID(-1), _name(""), _pass(""), _is_reg(false)
		{
			
		}

		User(const std::string& name, const std::string& pass) : _ID(max_ID + 1), _name(name), _pass(pass)
		{
			max_ID++;
			_is_reg = true;
		}
		
		bool reg();

		bool set_name(const std::vector<chat::User>& all_users);
		bool set_name(const std::string& name, const std::vector<chat::User>& all_users);

		bool set_pass();
		bool set_pass(const std::string& pass);

		int         get_ID()   const { return _ID; }
		std::string get_name() const { return _name; }
		
		bool check_pass(const std::string& pass) const { return (pass == _pass ? true : false); }

		// block for testing
		/*void print_info();
		void print_ID();
		void print_name();
		void print_pass();*/
		//
		
		User operator=(User user);

	private:

		int         _ID; 
		std::string _name;
		std::string _pass;
		bool        _is_reg;

		// counter for all users in chat
		static int  max_ID;
	};

	// auxiliary function to work with name & password
	bool uniq_user_name(const std::string& str, const std::vector<chat::User>& all_users);
	bool user_name_valid(const std::string& str);
	void user_name_req();

	bool user_pass_valid(const std::string& str);
	void user_pass_req();

}


