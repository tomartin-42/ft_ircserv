/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:28:27 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/28 13:38:21 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "user.hpp"

user::user(unsigned int id) : us_id(id), nick("init"), name("init"), 
	type(UNKNOW)
{
}

std::string		user::get_nick() const 
{
	return this->nick;
}

std::string		user::get_name() const 
{
	return this->name;
}

char			user::get_type() const 
{
	return this->type;
}

void			user::set_nick(const std::string& nick) 
{
	this->nick = nick;
}

void			user::set_name(const std::string& name) 
{
	this->name = name;
}

void			user::set_type(const char& type) 
{
	this->type = type;
}

void			user::set_us_id(const unsigned int& serv_id) 
{
	this->us_id = serv_id;
}

const connection*		user::get_connection_p()
{
	return (this->connection_p);
}

void			user::set_connection_p(connection* conn_p)
{
	this->connection_p = conn_p;
}

void			user::set_file_base_name()
{
	this->file_base_name = "USER ";
}
