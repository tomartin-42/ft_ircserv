/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:40:09 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/19 12:24:57 by tomartin         ###   ########.fr       */
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

void	connection::ready_to_lisen()
{
	this->set_poll_fd_events(POLLIN);
}

void	connection::ready_to_send()
{
	this->set_poll_fd_events(POLLOUT);
}

pollfd*	connection::get_poll_fd()
{
	return (&this->poll_fd);
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
	
void	connection::print_msg_recv(std::queue<std::string> print_q)
{
	std::queue<std::string>	aux(print_q);
	
	std::cout << "RECV QUEUE" << std::endl;
	while(!aux.empty())
	{
		std::cout << aux.front() << std::endl;
		aux.pop();
	}
	std::cout << "=============================================" << std::endl;
}

void	connection::print_msg_send(std::queue<std::string> print_q)
{
	std::queue<std::string>	aux(print_q);
	
	std::cout << "SEND QUEUE" << std::endl;
	while(!aux.empty())
	{
		std::cout << aux.front() << std::endl;
		aux.pop();
	}
	std::cout << "=============================================" << std::endl;
}
