/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:40:09 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/18 13:16:51 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connection.hpp"

connection::connection(int in_fd) : fd(in_fd) , c_user()
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
	time(&c_time);
	return std::string(ctime(&c_time));
}

ssize_t connection::send_msg(std::string str)
{
	return send(this->fd, &str[0], str.size(), MSG_DONTWAIT);
}

std::string	connection::recv_msg()
{
	char	buff[512];

	recv(this->fd, &buff, 512, MSG_DONTWAIT);
	return std::string(buff);
}

void	connection::ready_to_lisen()
{
	this->set_poll_fd_events(POLLIN);
}

void	connection::ready_to_send()
{
	this->set_poll_fd_events(POLLOUT);
}
