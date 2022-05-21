/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poll_fd.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:24:23 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/21 12:17:09 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _POLL_FD_HPP_
# define _POLL_FD_HPP_

#include <poll.h>

class poll_fd
{
	private:
		pollfd	polls;
	
	public:
		poll_fd();
		~poll_fd();
		poll_fd(const int& n_fd);
		poll_fd(const poll_fd& other);
		poll_fd& operator = (const poll_fd& other);
		int		get_polls_fd() const;
		short	get_polls_events() const;
		short	get_polls_revents() const;
		pollfd	get_polls() const;
		void	set_polls_fd(const int& n_fd);
		void	set_polls_events(const short& n_events);
		void	set_polls_revents(const short& n_revents);
		void	set_polls(const pollfd& n_polls);
};

#endif
