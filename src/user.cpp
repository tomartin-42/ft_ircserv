#include "user.hpp"

user::user() : nick("init"), name("init"), type(0) {}

std::string	user::get_nick() {return this->nick;}

std::string	user::get_name() {return this->name;}

int			user::get_type() {return this->type;}

void		user::set_nick(std::string nick) {this->nick = nick;}

void		user::set_name(std::string name) {this->name = name;}

void		user::set_type(int type) {this->type = type;}
