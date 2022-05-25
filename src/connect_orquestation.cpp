/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_orquestation.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:40:42 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/23 13:55:40 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect_orquestation.hpp"

//Add connection class to vector l_connections
//Need to gestion in and out connections
void	connect_orquestation::add_connection(connection &new_connect)
{
	pollfd*	aux;

	aux = this->poll_list.add_pollfd_fd(new_connect.get_fd());
	new_connect.set_poll_fd_point(aux);
	this->l_connections.push_back(new_connect);
	//this->l_connections.end()->set_poll_fd_point(aux);
}

//This function in responsible to check event in the 
//socket, them you can gestion comunication (send or recv)
//from socket
int		connect_orquestation::poll_connections()
{
	int	n_con;
	n_con = poll(this->poll_list.pointer_polls(), MAX_CONNECTIONS, 0);
	return n_con;
}

//This function check all of the fds socket and if 
//a socket is ready to lisen, send it a msg*
void	connect_orquestation::search_to_send()
{
	for(int i = 0; i < MAX_CONNECTIONS; i++)
	{
		if(this->poll_list.polls[i].revents == POLLOUT)
		{
			std::vector<connection>::iterator	it_c;
			for(it_c = this->l_connections.begin(); it_c != this->l_connections.end(); it_c++)
				if(this->poll_list.polls[i].fd == it_c->get_fd())
				{
					it_c->send_msg();//send_msg_queue
					this->poll_list.polls[i].revents = -1;
				}
		}
	}
}

//This function check all of the fds socket and if 
//a socket is ready to recv, recv it a msg
void	connect_orquestation::search_to_recv()
{
	for(int i = 0; i < MAX_CONNECTIONS; i++)
	{
		if(this->poll_list.polls[i].revents == POLLIN)
		{
			std::vector<connection>::iterator	it_c;
			for(it_c = this->l_connections.begin(); it_c != this->l_connections.end(); it_c++)
				if(this->poll_list.polls[i].fd == it_c->get_fd())
				{
					it_c->recv_msg();//send_msg_queue
					this->poll_list.polls[i].revents = -1;
				}
		}
	}
}

//Need to create a vector with all of pollfd struct to
//gestion the event comunication
//The datas of vector receive from connection class pollfd
void	connect_orquestation::check_connection_status()
{
	std::vector<connection>::iterator	it;

	for(it = l_connections.begin(); it != l_connections.end(); it++)
	{
		if(it->check_if_send_is_empty())
			poll_list.set_pollfd_event(it->get_fd(), POLLIN);
		else
			poll_list.set_pollfd_event(it->get_fd(), POLLOUT);
	}
}

void	connect_orquestation::gestion_communication()
{
	this->check_connection_status();
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

void	connect_orquestation::add_user(user& new_user)
{
	this->l_user.push_back(new_user);
}
