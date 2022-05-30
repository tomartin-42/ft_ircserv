/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:40:09 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/30 13:33:43 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connection.hpp"

connection::connection(int in_fd) : fd(in_fd)
{
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
		this->add_msg_log(this->msg_send.extract_msg_not_del(), 
				std::string("con_recv" + itoa(this->get_fd())));
		std::cout << "LEN= " << this->msg_send.msg_front_len() << std::endl;
		aux = send(this->fd, (this->msg_send.extract_msg_to_char().c_str()), this->msg_send.msg_front_len(), MSG_DONTWAIT);
		this->msg_send.pop_msg();
	}
	return aux;
}

std::string	connection::recv_msg()
{
	char	buff[512];

	bzero(buff, 512);
	recv(this->fd, &buff, 512, MSG_DONTWAIT);
	this->msg_recv.add_msg(buff);
	this->msg_send.add_msg(std::string(":HOLA"));
	this->msg_send.add_msg(std::string(":Welcome to the Internet Relay Network tomartin!tomartin@teamAchat.com"));
	//this->msg_send.add_msg(buff);
	//this->msg_send.add_msg(std::string("HOLA\x0d\x0a"));
	this->add_msg_log(std::string(buff), std::string("con_send " + itoa(this->get_fd())));
	return std::string(buff);
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

void	connection::set_poll_fd_point(pollfd* point)
{
	this->poll_fd_point = point;
}

const user*	connection::get_user_point()
{
	return(this->user_point);
}

void	connection::set_user_point(user* user_p)
{
	this->user_point = user_p;
}
void	connection::set_file_base_name()
{
	this->file_base_name = "connection";
}
