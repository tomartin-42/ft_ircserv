/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conections.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:13:50 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/18 08:38:03 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONNECTION_HPP_
# define _CONNECTION_HPP_

#include <poll.h>
#include <ctime>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include "user.hpp"

class connection
{
	private:
		const int	fd;
		pollfd		poll_fd;
		time_t		c_time;
		user		c_user;

	public:
		connection(int in_fd);

		void		set_poll_fd_fd(const int fd);
		void		set_poll_fd_events(const short event);
		short		get_poll_fd_revents();
		int			get_fd();
		void		set_time();
		std::string	get_time();
		ssize_t		send_msg(const std::string str);
		std::string	recv_msg();
};

#endif
