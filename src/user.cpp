#include "user.hpp"

user::user() : nick("init"), name("init"), type(UNKNOW) {}

std::string&	user::get_nick() {return this->nick;}

std::string&	user::get_name() {return this->name;}

char&			user::get_type() {return this->type;}

void			user::set_nick(const std::string& nick) {this->nick = nick;}

void			user::set_name(const std::string& name) {this->name = name;}

void			user::set_type(const char& type) {this->type = type;}
