/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:28:27 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/25 13:28:30 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "user.hpp"

user::user() : nick("init"), name("init"), type(UNKNOW) {}

std::string		user::get_nick() const 
{return this->nick;}

std::string		user::get_name() const 
{return this->name;}

char			user::get_type() const 
{return this->type;}

void			user::set_nick(const std::string& nick) 
{this->nick = nick;}

void			user::set_name(const std::string& name) 
{this->name = name;}

void			user::set_type(const char& type) 
{this->type = type;}

void			user::set_us_id(const unsigned int& serv_id) 
{this->us_id = serv_id;}
