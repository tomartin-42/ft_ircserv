/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_orquestation.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:40:42 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/22 20:18:43 by tomartin         ###   ########.fr       */
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
	int	n_con;
	n_con = poll(&this->ref_pollfd[0], ref_pollfd.size() , 0);
	return n_con;
}

//This function check all of the fds socket and if 
//a socket is ready to lisen, send it a msg*
void	connect_orquestation::search_to_send()
{
	std::vector<pollfd>::iterator		it_pollfd;

	for(it_pollfd = this->ref_pollfd.begin(); it_pollfd != this->ref_pollfd.end(); it_pollfd++)
	{
		if(it_pollfd->revents == POLLOUT)
		{
			std::vector<connection>::iterator it_c;
			for(it_c = this->l_connections.begin(); it_c != this->l_connections.end(); it_c++)
				if(it_pollfd->fd == it_c->get_fd())
				{
					it_c->send_msg();//send_msg_queue
					it_c->set_poll_fd_revents(0);
				}
		}
	}
}

//This function check all of the fds socket and if 
//a socket is ready to recv, recv it a msg
void	connect_orquestation::search_to_recv()
{
	std::vector<pollfd>::iterator		it_pollfd;

	for(it_pollfd = this->ref_pollfd.begin(); it_pollfd != this->ref_pollfd.end(); it_pollfd++)
	{
		if(it_pollfd->revents == POLLIN)
		{
			std::vector<connection>::iterator it_c;
			for(it_c = this->l_connections.begin(); it_c != this->l_connections.end(); it_c++)
				if(it_pollfd->fd == it_c->get_fd())
				{
					it_c->recv_msg();//send_msg_queue
					it_c->set_poll_fd_revents(0);
				}
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
	{
		ref_pollfd.push_back(it->get_poll_fd());
	}
}

void	connect_orquestation::check_connection_status()
{
	std::vector<connection>::iterator	it;

	for(it = l_connections.begin(); it != l_connections.end(); it++)
	{
		if(it->check_if_send_is_empty())
		{
			it->ready_to_recv();
		}
		else
		{
			it->ready_to_send();
		}
	}
}

void	connect_orquestation::gestion_communication()
{
	this->ref_pollfd.clear();
	this->check_connection_status();
	this->init_ref_pollfd();
	this->poll_connections();
	this->search_to_send();
	this->search_to_recv();
}

void	connect_orquestation::print_msgs()
{
	std::vector<connection>::iterator	it;

	for(it = l_connections.begin(); it != l_connections.end(); it++)
	{
		it->print_msg_recv();
		it->print_msg_send();
	}
}
