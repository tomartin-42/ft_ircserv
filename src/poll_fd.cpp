/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poll_fd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:37:45 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/23 13:26:54 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "poll_fd.hpp"

poll_fd::poll_fd() 
{
	memset(this->polls, -1, sizeof(pollfd) * MAX_CONNECTIONS);
	this->empty_pollfd.fd = -1;
	this->empty_pollfd.events = -1;
	this->empty_pollfd.revents = -1;
}

poll_fd::~poll_fd() {}

int	poll_fd::add_pollfd_fd(const int& n_fd)
{
	for(int i = 0; i < MAX_CONNECTIONS; i++)
	{
		if(this->polls[i].fd == -1)
		{
			this->polls[i].fd = n_fd;
			return i;
		}
	}
	return 0;
}

int	poll_fd::num_activate_fds() const
{
	int res = 0;

	for(int i = 0; i < MAX_CONNECTIONS; i++)
	{
		if (this->polls[i].fd != -1)
			res++;
	}
	return res;
}

pollfd poll_fd::get_pollfd_values(const int& fd) const
{
	for(int i = 0; i < MAX_CONNECTIONS; i++)
	{
		if(this->polls[i].fd == fd)
			return (this->polls[i]);
	}
	return (this->empty_pollfd);
}

short	poll_fd::get_pollfd_event(const int& fd) const
{
	for(int i = 0; i < MAX_CONNECTIONS; i++)
	{
		if(this->polls[i].fd == fd)
			return (this->polls[i].events);

	}
	return (-1);
}

void	poll_fd::set_pollfd_event(const int& fd, const short& n_event)
{
	for(int i = 0; i < MAX_CONNECTIONS; i++)
	{
		if(this->polls[i].fd == fd)
		{
			this->polls[i].events = n_event;
			break ;
		}
	}
}

short	poll_fd::get_pollfd_revent(const int& fd) const
{
	for(int i = 0; i < MAX_CONNECTIONS; i++)
	{
		if(this->polls[i].fd == fd)
			return (this->polls[i].revents);
	}
	return (-1);
}

void	poll_fd::set_pollfd_revent(const int& fd, const short& n_revent)
{
	for(int i = 0; i < MAX_CONNECTIONS; i++)
	{
		if(this->polls[i].fd == fd)
		{
			this->polls[i].revents = n_revent;
			break ;
		}
	}
}

bool	poll_fd::fd_is_in_polls(const int& fd) const
{
	bool	resp = false;

	for (int i = 0; i < MAX_CONNECTIONS; i++)
	{
		if(this->polls[i].fd == fd)
			return true;
	}
	return resp;
}

void	poll_fd::dell_polls_element(const int& fd)
{
	for(int i = 0; i < MAX_CONNECTIONS; i++)
	{
		if(this->polls[i].fd == fd)
			polls[i] = this->empty_pollfd;
	}
}

pollfd*	poll_fd::pointer_polls()
{
	return(&(this->polls[0]));
}


pollfd* poll_fd::one_point_polls(const int& fd)
{
	for(int i = 0; i < MAX_CONNECTIONS; i++)
	{
		if(this->polls[i].fd == fd)
			return (&polls[i]);
	}
	return (NULL);
}

