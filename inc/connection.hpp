/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conections.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:13:50 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/18 13:52:06 by tomartin         ###   ########.fr       */
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
#include "user.hpp"

class connection
{
	private:
		const int				fd;
		pollfd					poll_fd;
		time_t					c_time;
		user					c_user;
		std::queue<std::string> msg_recv;	//recv msg queue
		std::queue<std::string> msg_send;	//to send msg queue
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
		void		ready_to_lisen();
		void		ready_to_send();
		ssize_t		send_msg(const std::string str);
		std::string	recv_msg();
		void		print_log();
};

#endif
