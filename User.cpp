#pragma once

#include <iostream>

#include "User.h"
#include "Interface.h"

namespace Chat {

	int Chat::User::max_ID = 0;

	// register user with valid name & password
	bool User::reg() {
		if (is_reg)
			return false;
		
		ID = max_ID + 1;
		max_ID++;
		is_reg = true;

		return true;
	}

	bool User::set_name(const std::vector<Chat::User>* all_users) {
		std::string str = "";
		do {
			user_name_req();
			std::cout << "Input user name:  ";
			std::cin >> str;
		} while (!set_name(str, all_users));
		return true;
	}
	bool User::set_name(std::string _name, const std::vector<Chat::User>* all_users) {
		if (!uniq_user_name(_name, all_users)) {
			std::cout << "User name \"" << _name << "\" already exist!\n"
				<< "Enter another user name!\n";
			return false;
		}
		if (!user_name_valid(_name)) {
			std::cout << "Invalid user name!\n";
			return false;
		}
		name = _name;
		return true;
	}

	bool User::set_pass() {
		std::string str = "";
		do {
			user_pass_req();
			std::cout << "Input password:  ";
			std::cin >> str;
		} while (!set_pass(str));
		return true;
	}
	bool User::set_pass(std::string _pass) {
		if (pass != "") {
			std::cout << "Password already exist!\n"
				<< "Do you want to change it?\n";
			bool flag = true;
			while (flag) {
				std::cout << "Input \">>yes\" or \">>no\" command:  ";
				std::string str;
				std::cin >> str;
				Interface::Command cmd = Interface::get_command(str);
				switch (cmd) {
				case Interface::Command::YES:
					flag = false;
					break;
				case Interface::Command::NO:
					std::cout << "Password didn't changed\n";
					return true;
				default:
					std::cout << "Bad command!\n";
				}
			}
		}
		if (!user_pass_valid(_pass))
			return false;
		pass = _pass;
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
	
	// auxiliary function to work with name & password
	bool uniq_user_name(std::string str, const std::vector<Chat::User>* all_users) {
		for (int i = 0; i < all_users->size(); i++)
			if (str == (*all_users)[i].get_name())
				return false;
		return true;
	}

	bool user_name_valid(std::string str) {
		if (str.length() > 0 && str[0] == '>') return false;
		if (str.length() > 1 && str[0] == '>' && str[1] == '>') return false;

		return true;
	}

	void user_name_req() {
		std::cout << "User name can\'t start from \'>\' or \'>>\'!\n";
	}

	bool user_pass_valid(std::string str) {
		if (str.length() < 8)
			return false;

		int A_simbol = 0;
		int a_simbol = 0;
		int num_simbol = 0;
		int spec_simbol = 0;

		for (int i = 0; i < str.size(); i++) {
			if (Interface::char_is_A_simbol(str[i])) {
				A_simbol++;
				continue;
			}
			if (Interface::char_is_a_simbol(str[i])) {
				a_simbol++;
				continue;
			}
			if (Interface::char_is_num_simbol(str[i])) {
				num_simbol++;
				continue;
			}
			if (Interface::char_is_spec_simbol(str[i])) {
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

	User User::operator=(User user)
	{
		ID = user.ID;
		name = user.name;
		pass = user.pass;
		is_reg = user.is_reg;

		return *this;
	}
}
	
