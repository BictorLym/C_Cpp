#include <iostream>
#include <string>
#include <regex>

inline std::string trim(std::string& str) {
	str.erase(0, str.find_first_not_of(' '));//prefixing spaces 
	str.erase(str.find_last_not_of(' ') + 1);//surfixing spaces 
	return str;
}

