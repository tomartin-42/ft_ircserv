/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_orquestation.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:40:42 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/19 12:26:30 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect_orquestation.hpp"

//Add connection class to vector l_connections
//Need to gestion in and out connections
void	connect_orquestation::add_connection(connection &new_connect)
{
	this->l_connections.push_back(new_connect);
}

//This function in responsible to check event in the 
//socket, them you can gestion comunication (send or recv)
//from socket
int		connect_orquestation::poll_connections()
{
	this->init_ref_pollfd();
	return (poll(this->ref_pollfd[0], ref_pollfd.size(), 0));
}

//This function check all of the fds socket and if 
//a socket is ready to lisen, send it a msg
void	connect_orquestation::search_to_send()
{
	std::vector<connection>::iterator	it;

	for(it = this->l_connections.begin(); it != this->l_connections.end(); it++)
	{
		if(it->get_poll_fd_revents() == POLLOUT)
		{
			it->send_msg();//send_msg_queue
		}
	}
}

//This function check all of the fds socket and if 
//a socket is ready to recv, recv it a msg
void	connect_orquestation::search_to_recv()
{
	std::vector<connection>::iterator	it;

	for(it = this->l_connections.begin(); it != this->l_connections.end(); it++)
	{
		if(it->get_poll_fd_revents() == POLLIN)
		{
			it->recv_msg();//recv_msg_queue
		}
	}
}

//Need to create a vector with all of pollfd struct to
//gestion the event comunication
//The datas of vector receive from connection class pollfd
void	connect_orquestation::init_ref_pollfd()
{
	std::vector<connection>::iterator	it;

	for (it = this->l_connections.begin(); it != this->l_connections.end(); it++)
		ref_pollfd.push_back(it->get_poll_fd());
}

