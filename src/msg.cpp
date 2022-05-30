/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:51:19 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/30 13:35:13 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msg.hpp"

bool	msg::check_if_empty() const
{
	if(this->msg_q.empty())
		return true;
	return false;
}

std::string	msg::get_next_msg()
{
	std::string::size_type	point;

	point = this->buff_aux.find("\x0d\x0a", 0);
	std::string	ret(this->buff_aux.substr(0, (point)));
	this->buff_aux.erase(0, (point + 2));
	return ret;
}

void	msg::add_msg(const char* str) 
{
	this->buff_aux.append(str);

	while(this->buff_aux.find("\x0d\x0a", 0) != std::string::npos)
		this->msg_q.push(this->get_next_msg());
}

void	msg::add_msg(const std::string str)
{
	this->msg_q.push(str);
}

std::string	msg::extract_msg()
{
	return this->msg_q.front();
}

int	msg::number_msg() const
{
	return msg_q.size();
}

msg::~msg()
{
	while(!this->msg_q.empty())
		this->msg_q.pop();
}

void	msg::print_all_msg()
{
	std::queue<std::string>	aux(this->msg_q);

	while(!aux.empty())
	{
		std::cout << "MSG: " << aux.front() << std::endl;
		aux.pop();
	}
}

int		msg::msg_q_size()
{
	return (this->msg_q.size());
}

int		msg::msg_front_len()
{
	return (this->msg_q.front().length());
}

void	msg::pop_msg()
{
	this->msg_q.pop();
}
