/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:40:09 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/16 20:15:12 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connection.hpp"

void	connection::set_poll_fd_fd(int fd const)
{
	this->poll_fd.fd = fd;
}

void	connection::set_poll_fd_events(short event const)
{
	this->poll_fd.events = event;
}

const short	connection::get_poll_fd_revent()
{
	return this->poll_fd.revents;
}
