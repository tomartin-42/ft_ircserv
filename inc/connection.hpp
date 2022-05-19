/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conections.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:13:50 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/19 12:25:21 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONNECTION_HPP_
# define _CONNECTION_HPP_

#include <poll.h>
#include <ctime>
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
		msg						msg_send;
		msg						msg_recv;
		//std::queue<std::string> msg_recv;	//recv msg queue
		//std::queue<std::string> msg_send;	//to send msg queue
		std::vector<std::string> log;		//comunication log

		void		set_poll_fd_events(const short event);
		void		add_log(bool sor, std::string msg);

	public:
		connection(int in_fd);

		void		set_poll_fd_fd(const int fd);
		short		get_poll_fd_revents();
		int			get_fd();
		pollfd*		get_poll_fd();
		void		set_time();
		std::string	get_time();
		void		ready_to_recv();
		void		ready_to_send();
		ssize_t		send_msg();
		std::string	recv_msg();
		void		print_log();
		void		print_msg_recv(std::queue<std::string> print_q);
		void		print_msg_send(std::queue<std::string> print_q);
		bool		check_if_send_is_empty();
};

#endif
