/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conections.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:13:50 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/23 13:32:22 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONNECTION_HPP_
# define _CONNECTION_HPP_

#include <poll.h>
#include <ctime>
#include <cstdio>
#include <string>
#include <strings.h>
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include "msg.hpp"
#include "user.hpp"

class connection
{
	private:
		const int					fd;
		time_t						c_time;
		user						c_user;
		pollfd*						poll_fd_point;
		msg							msg_send;	//msg_send queue
		msg							msg_recv;	//msg_recv queue
		std::vector<std::string>	log;		//comunication log

		void		add_log(bool sor, std::string msg);

	public:
		connection(int in_fd);

		int			get_fd() const;
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
		void		set_poll_fd_point(pollfd* point);
		pollfd*		get_poll_fd_point();

		void		set_c_user_id(const unsigned int& id);
};

#endif
