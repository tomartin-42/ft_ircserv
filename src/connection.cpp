/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:40:09 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/22 17:58:16 by tomartin         ###   ########.fr       */
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

short	connection::get_poll_fd_events()
{
	return (this->poll_fd.events);
}

short	connection::get_poll_fd_revents()
{
	return (this->poll_fd.revents);
}

void	connection::set_poll_fd_revents(const short new_revents)
{
	this->poll_fd.revents = new_revents;
}

int	connection::get_fd() const
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

ssize_t connection::send_msg()
{
	ssize_t	aux = 0;
	
	if (!msg_send.check_if_empty())
	{
		aux = send(this->fd, (this->msg_send.extract_msg_to_char()), 512, MSG_DONTWAIT);
	}
	return aux;
}

std::string	connection::recv_msg()
{
	char	buff[512];

	recv(this->fd, &buff, 512, MSG_DONTWAIT);
	this->msg_recv.add_msg(buff);
	return std::string(buff);
}

void	connection::ready_to_recv()
{
	this->set_poll_fd_events(POLLIN);
}

void	connection::ready_to_send()
{
	this->set_poll_fd_events(POLLOUT);
}

pollfd	connection::get_poll_fd()
{
	return (this->poll_fd);
}

void	connection::add_log(bool sor, std::string msg)
{
	std::string	aux;

	if(sor == 0)
		aux = this->get_time() + " SEND " + msg;
	else if(sor == 1)
		aux= this->get_time() + " RECV " + msg; 
	this->log.push_back(aux);
}

void connection::print_log()
{
	std::vector<std::string>::iterator	it;

	for(it = this->log.begin(); it != this->log.end(); it++)
		std::cout << this->fd << " " << *it << std::endl;
}
	
void	connection::print_msg_recv()
{
	std::cout << "RECV QUEUE FD:" << this->get_fd() << std::endl;
	this->msg_recv.print_all_msg();
	std::cout << "=============================================" << std::endl;
}

void	connection::print_msg_send()
{
	std::cout << "SEND QUEUE FD:" << this->get_fd() << std::endl;
	this->msg_send.print_all_msg();
	std::cout << "=============================================" << std::endl;
}

bool	connection::check_if_send_is_empty()
{
	return this->msg_send.check_if_empty();
}
