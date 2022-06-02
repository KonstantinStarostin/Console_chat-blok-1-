#pragma once

#include <iostream>

#include "Interface.h"

Interface::Command Interface::get_command(std::string &str) {
	// Command must start with ">>" simbols
	if (str.length() <= 2)
	    return Interface::Command::NO_COMMAND;

	if (str[0] != '>' || str [1] != '>')
		return Interface::Command::NO_COMMAND;
		
	std::string str_cmd;
	for (int i = 2; i < str.length(); i++)
		str_cmd += str[i];

	if (str_cmd == "yes")    return Interface::Command::YES;
	if (str_cmd == "no")     return Interface::Command::NO;
	if (str_cmd == "reg")    return Interface::Command::REG;
	if (str_cmd == "log")    return Interface::Command::LOGIN;
	if (str_cmd == "chg")    return Interface::Command::CHANGE;
	if (str_cmd == "room")   return Interface::Command::ROOM;
	if (str_cmd == "user")   return Interface::Command::USER;
	if (str_cmd == "name")   return Interface::Command::NAME;
	if (str_cmd == "pass")   return Interface::Command::PASSWORD;
	if (str_cmd == "all")    return Interface::Command::ALL;
	if (str_cmd == "quit")   return Interface::Command::QUIT;
	if (str_cmd == "info")   return Interface::Command::INFO;

	return Interface::Command::NO_COMMAND;
}

bool Interface::char_is_A_simbol(char ch) {
	return (ch >= 'A' && ch <= 'Z') ? true : false;
}
bool Interface::char_is_a_simbol(char ch) {
	return (ch >= 'a' && ch <= 'z') ? true : false;
}
bool Interface::char_is_num_simbol(char ch) {
	return (ch >= '0' && ch <= '9') ? true : false;
}
bool Interface::char_is_spec_simbol(char ch) {
	if (ch >= '!' && ch <= '/')  return true;
	if (ch >= ':' && ch <= '@')  return true;
	if (ch >= '[' && ch <= '\'') return true;
	if (ch >= '{' && ch <= '~')  return true;

	return false;
}
