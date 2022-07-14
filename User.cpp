#pragma once

#include <iostream>

#include "User.h"
#include "Interface.h"

namespace chat {

	int chat::User::max_ID = 0;

	// register user with valid name & password
	bool User::reg() {
		if (_is_reg)
			return false;
		
		_ID = max_ID + 1;
		max_ID++;
		_is_reg = true;

		return true;
	}

	bool User::set_name(const std::vector<chat::User>& all_users) {
		std::string str;
		do {
			user_name_req();
			std::cout << "Input user name:  ";
			std::cin >> str;
		} while (!set_name(str, all_users));
		return true;
	}
	
	bool User::set_name(const std::string& name, const std::vector<chat::User>& all_users) {
		if (!uniq_user_name(name, all_users)) {
			std::cout << "User name \"" << name << "\" already exist!\n"
				<< "Enter another user name!\n";
			return false;
		}
		if (!user_name_valid(name)) {
			std::cout << "Invalid user name!\n";
			return false;
		}
		_name = name;
		return true;
	}

	bool User::set_pass() {
		std::string str;
		do {
			user_pass_req();
			std::cout << "Input password:  ";
			std::cin >> str;
		} while (!set_pass(str));
		return true;
	}
	
	bool User::set_pass(const std::string& pass) {
		if (_pass != "") {
			std::cout << "Password already exist!\n"
				<< "Do you want to change it?\n";
			bool flag = true;
			while (flag) {
				std::cout << "Input \">>yes\" or \">>no\" command:  ";
				std::string str;
				std::cin >> str;
				interface::Command cmd = interface::get_command(str);
				switch (cmd) {
				case interface::Command::YES:
					flag = false;
					break;
				case interface::Command::NO:
					std::cout << "Password didn't changed\n";
					return true;
				default:
					std::cout << "Bad command!\n";
				}
			}
		}
		if (!user_pass_valid(pass))
			return false;
		_pass = pass;
		return true;
	}

	// block for testing
	/*void User::print_info() {
		print_ID();
		print_name();
		print_pass();
	}
	void User::print_ID()   { std::cout << "User ID  : " << ID << std::endl; }
	void User::print_name() { std::cout << "User name: " << name << std::endl; }
	void User::print_pass() { std::cout << "User pass: " << pass << std::endl; }*/
	//
	
	User User::operator=(User user)
	{
		_ID = user._ID;
		_name = user._name;
		_pass = user._pass;
		_is_reg = user._is_reg;

		return *this;
	}
	
	// auxiliary function to work with name & password
	bool uniq_user_name(const std::string& str, const std::vector<chat::User>& all_users) {
		
		for (const auto& all_user : all_users)
			if (str == all_user.get_name())
				return false;
		return true;
		
	}

	bool user_name_valid(const std::string& str) {
		if (str.length() > 0 && str[0] == '>') return false;
		if (str.length() > 1 && str[0] == '>' && str[1] == '>') return false;

		return true;
	}

	void user_name_req() {
		std::cout << "User name can\'t start from \'>\' or \'>>\'!\n";
	}

	bool user_pass_valid(const std::string& str) {
		if (str.length() < 8)
			return false;

		int A_simbol = 0;
		int a_simbol = 0;
		int num_simbol = 0;
		int spec_simbol = 0;

		for (int i = 0; i < str.size(); i++) {
			if (interface::char_is_A_simbol(str[i])) {
				A_simbol++;
				continue;
			}
			if (interface::char_is_a_simbol(str[i])) {
				a_simbol++;
				continue;
			}
			if (interface::char_is_num_simbol(str[i])) {
				num_simbol++;
				continue;
			}
			if (interface::char_is_spec_simbol(str[i])) {
				spec_simbol++;
				continue;
			}
		}

		if (A_simbol == 0 || a_simbol == 0 || num_simbol == 0 || spec_simbol == 0)
			return false;

		return true;
	}

	void user_pass_req() {
		std::cout << "Password must be no less then 8 simbols" << std::endl
			<< "and contain upper-case & lower-case letters, numbers & special simbols\n";
	}
	


}

	
