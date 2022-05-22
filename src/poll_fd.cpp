/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poll_fd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:37:45 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/22 20:20:41 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "poll_fd.hpp"

poll_fd::poll_fd() 
{
	memset(this->polls, -1, sizeof(pollfd) * MAX_CONNECTIONS);
}
/*
poll_fd::~poll_fd() {}

poll_fd::poll_fd(const int& n_fd)
{	
	this->polls.fd = n_fd;
	this->polls.events = 0;
	this->polls.revents = 0;
}

poll_fd::poll_fd(const poll_fd& other) 
{
	this->polls.fd = other.polls.fd;
	this->polls.events = other.polls.events;
	this->polls.revents = other.polls.revents;
}

poll_fd&	poll_fd::operator = (const poll_fd& other)
{
	this->polls.fd = other.polls.fd;
	this->polls.events = other.polls.events;
	this->polls.revents = other.polls.revents;
	return *this;
}

int		poll_fd::get_polls_fd() const {return (this->polls.fd);}

short	poll_fd::get_polls_events() const {return (this->polls.events);}

short	poll_fd::get_polls_revents() const {return (this->polls.revents);}

pollfd	poll_fd::get_polls() const {return (this->polls);}

void	poll_fd::set_polls_fd(const int& n_fd) {this->polls.fd = n_fd;}

void	poll_fd::set_polls_events(const short& n_events) 
{
	this->polls.events = n_events;
}

void	poll_fd::set_polls_revents(const short& n_revents)
{
	this->polls.revents = n_revents;
}

void	poll_fd::set_polls(const pollfd& n_polls)
{
	this->polls = n_polls;
}
*/
