/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conections.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:13:50 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/04 13:37:22 by tomartin         ###   ########.fr       */
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
#include "log.hpp"
#include "user.hpp"
#include "ft_ircserv.hpp"
#include "answer_maker.hpp"

class user;

class connection : public log
{
	private:
		const int					fd;
		time_t						c_time;
		pollfd*						poll_fd_point;
		msg							msg_send;	//msg_send queue
		msg							msg_recv;	//msg_recv queue
		const user*					user_point; //I think to change pointer to 
                                                //inheritance from gestion of user
                                                //I think is beter for abstraction 
                                                //c++ concept

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
		void		print_msg_recv();
		void		print_msg_send();
		bool		check_if_send_is_empty();
		void		set_poll_fd_point(pollfd* point);
		pollfd*		get_poll_fd_point();
		const user*	get_user_point();
		void		set_user_point(user* user_p);

		void		set_file_base_name();
};

#endif
