/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_socket.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:56:05 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/20 12:21:53 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.hpp"
#include <cstdio>

my_socket::my_socket(const int port)
{
	this->data_socket.sin_family = AF_INET;
	this->data_socket.sin_addr.s_addr = INADDR_ANY;
	this->data_socket.sin_port = htons(port);
	this->data_socket_len = sizeof(data_socket);
	this->port = port;
}

my_socket::~my_socket()
{
	close(this->socket_fd);
}

//Tis function return(std::string) the first msg in the queue and delete
//this element. If the queue is empty return NULL
std::string	my_socket::get_msg()
{
	std::string	aux;

	if(!this->msg_queue.empty())
		return(NULL);
	aux = this->msg_queue.front();
	this->msg_queue.pop();
	return aux;
}

//Print the msg_queue. Only use to debug
void	my_socket::print_msg_queue()
{
	std::string	aux;
	
	while (this->msg_queue.empty() != 1)
	{
		aux = this->msg_queue.front();
		this->msg_queue.pop();
		std::cout << aux;
	}
}

void	my_socket::accept_new_connect()
{
	int	new_fd;
			
	new_fd = accept(this->socket_fd, (struct sockaddr *) &(this->data_socket), 
			(socklen_t *) &(this->data_socket_len));
	fcntl(new_fd, F_SETFL, O_NONBLOCK);
	fds_connect_ready.push(new_fd);
}

//When call this finction, if there are petitions POLLIN in my_socket,
//load in fds_connect_ready(vector), if not there POLLIN petitions
//do nothing. This function return a int: -1 if error, 0 if not have POLLIN petitions
//if there ar POLLIN petitions return the numbers petitions
int	my_socket::load_in_connections()
{
	int	check;

	check = poll(&(this->poll_fd), 1, 1000);
	if(check > 0)
		this->accept_new_connect();
	return check;
}

void	my_socket::init_socket()
{
	int	enable; //need to enable setsockop values

	enable = 1; //need to enable setsockopt values
	this->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(this->socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &enable, sizeof(enable));
	fcntl(this->socket_fd, F_SETFL, O_NONBLOCK);
	bind(this->socket_fd, (struct sockaddr *) &(this->data_socket), sizeof(data_socket));
	listen(this->socket_fd, 10);
	poll_fd.fd = this->socket_fd;
	poll_fd.events = POLLIN;
}

int		my_socket::get_port() const // geter port
{
	return (this->port);
}

connection	my_socket::extract_new_connection()
{
	connection	aux(this->fds_connect_ready.front());
	this->fds_connect_ready.pop();
	return (aux);
}

bool	my_socket::pending_connection()
{
	if(!this->fds_connect_ready.empty())
		return true;
	return false;
}
