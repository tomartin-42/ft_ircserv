/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conections.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:13:50 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/20 12:28:25 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONNECTION_HPP_
# define _CONNECTION_HPP_

#include <poll.h>
#include <ctime>
#include <cstdio>
#include <string>
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include "msg.hpp"
#include "user.hpp"

class connection
{
	private:
		const int				fd;
		pollfd					poll_fd;
		time_t					c_time;
		user					c_user;
		msg						msg_send;	//msg_send queue
		msg						msg_recv;	//msg_recv queue
		std::vector<std::string> log;		//comunication log

		void		set_poll_fd_events(const short event);
		void		add_log(bool sor, std::string msg);

	public:
		connection(int in_fd);

		void		set_poll_fd_fd(const int fd);
		short		get_poll_fd_events();
		short		get_poll_fd_revents();
		void		set_poll_fd_revents(const short new_revents);
		int			get_fd();
		pollfd		get_poll_fd();
		void		set_time();
		std::string	get_time();
		void		ready_to_recv();
		void		ready_to_send();
		ssize_t		send_msg();
		std::string	recv_msg();
		void		print_log();
		void		print_msg_recv();
		void		print_msg_send();
		bool		check_if_send_is_empty();
};

#endif
