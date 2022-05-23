/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poll_fd.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:24:23 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/23 13:51:18 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _POLL_FD_HPP_
# define _POLL_FD_HPP_

#include <poll.h>
#include <cstring>
#include "ft_ircserv.hpp"

struct poll_fd
{
		pollfd	polls[MAX_CONNECTIONS];
		pollfd	empty_pollfd;
	
		poll_fd();
		~poll_fd();

		int		num_activate_fds() const;
		pollfd*	add_pollfd_fd(const int& n_fd);
		pollfd	get_pollfd_values(const int& fd) const;
		short	get_pollfd_event(const int& fd) const;
		void	set_pollfd_event(const int& fd, const short& n_event);
		short	get_pollfd_revent(const int& fd) const;
		void	set_pollfd_revent(const int& fd, const short& n_revent);
		bool	fd_is_in_polls(const int& fd) const;
		void	dell_polls_element(const int& fd);
		pollfd*	pointer_polls();
		pollfd*	one_point_polls(const int& fd);
};

#endif
