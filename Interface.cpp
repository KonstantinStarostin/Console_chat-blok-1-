#pragma once

#include <iostream>

#include "Interface.h"

interface::Command interface::get_command(std::string &str) {
	// Command must start with ">>" simbols
	if (str.length() <= 2)
	    return interface::Command::NO_COMMAND;

	if (str[0] != '>' || str [1] != '>')
		return interface::Command::NO_COMMAND;
		
	std::string str_cmd;
	for (int i = 2; i < str.length(); i++)
		str_cmd += str[i];

	if (str_cmd == "yes")    return interface::Command::YES;
	if (str_cmd == "no")     return interface::Command::NO;
	if (str_cmd == "reg")    return interface::Command::REG;
	if (str_cmd == "log")    return interface::Command::LOGIN;
	if (str_cmd == "chg")    return interface::Command::CHANGE;
	if (str_cmd == "room")   return interface::Command::ROOM;
	if (str_cmd == "user")   return interface::Command::USER;
	if (str_cmd == "name")   return interface::Command::NAME;
	if (str_cmd == "pass")   return interface::Command::PASSWORD;
	if (str_cmd == "all")    return interface::Command::ALL;
	if (str_cmd == "quit")   return interface::Command::QUIT;
	if (str_cmd == "info")   return interface::Command::INFO;

	return interface::Command::NO_COMMAND;
}

bool interface::char_is_A_simbol(char ch) {
	return (ch >= 'A' && ch <= 'Z') ? true : false;
}
bool interface::char_is_a_simbol(char ch) {
	return (ch >= 'a' && ch <= 'z') ? true : false;
}
bool interface::char_is_num_simbol(char ch) {
	return (ch >= '0' && ch <= '9') ? true : false;
}
bool interface::char_is_spec_simbol(char ch) {
	if (ch >= '!' && ch <= '/')  return true;
	if (ch >= ':' && ch <= '@')  return true;
	if (ch >= '[' && ch <= '`') return true;
	if (ch >= '{' && ch <= '~')  return true;

	return false;
}
