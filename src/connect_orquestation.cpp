/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_orquestation.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:40:42 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/18 13:52:09 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect_orquestation.hpp"

void	connect_orquestation::add_connection(connection &new_connect)
{
	this->l_connections.push_back(new_connect);
}

int		connect_orquestation::poll_connections()
{
	this->init_ref_pollfd();
	return (poll(&(this->ref_pollfd), l_connections.size(), 0));
}

void	connect_orquestation::search_to_send()
{
	std::vector<connection>::iterator	it;

	for(it = this->l_connections.begin(); it != this->l_connections.end(); it++)
	{
		if(it->get_poll_fd_revents() == POLLOUT)
			;
			//send_msg_queue
	}
}

void	connect_orquestation::search_to_recv()
{
	std::vector<connection>::iterator	it;

	for(it = this->l_connections.begin(); it != this->l_connections.end(); it++)
	{
		if(it->get_poll_fd_revents() == POLLIN)
			;
			//recv_msg_queue
	}
}

void	connect_orquestation::init_ref_pollfd()
{
	std::vector<connection>::iterator	it;

	for (it = l_connections.begin(); it != l_connections.end(); it++)
		ref_pollfd.push(it->get_poll_fd())
}

