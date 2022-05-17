/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:40:09 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/17 11:14:06 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connection.hpp"

connection::connection(int in_fd) : fd(in_fd)
{
	this->poll_fd.fd = in_fd;
}

void	connection::set_poll_fd_fd(const int fd)
{
	this->poll_fd.fd = fd;
}

void	connection::set_poll_fd_events(const short event)
{
	this->poll_fd.events = event;
}

short	connection::get_poll_fd_revents()
{
	return (this->poll_fd.revents);
}

int	connection::get_fd()
{
	return (this->fd);
}

void connection::set_time()
{
	time(&this->c_time);
}

std::string	connection::get_time()
{
	struct tm	aux_tm;
	char		buff[80];

	time(&this->c_time);
	aux_tm = localtime(&this->c_time);
	strftime(buff, 80, "%x %X", aux_tm);
	return std::string(buff);
}
