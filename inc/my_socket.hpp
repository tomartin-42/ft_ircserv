/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_socket.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:56:00 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/17 10:29:00 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MY_SOCKET_HPP_
# define _MY_SOCKET_HPP_

#include <vector>
#include <cstring>
#include <unistd.h>
#include <iostream>
#include <queue>
#include <string>
#include <arpa/inet.h>
#include <fcntl.h>								// To fcntl function
#include <unistd.h>
#include <sys/socket.h>							// To socket
#include <netinet/in.h>							// To struct sockaddr_in
#include <sys/types.h>
#include <poll.h>								// To poll
#include <fcntl.h>								// To fcntl

class	my_socket
{
	private:
		int						port;			//Port when the server lisen	
		int						socket_fd;
		pollfd					poll_fd;
		struct sockaddr_in		data_socket;
		int						data_socket_len; //Need to accept function
		std::queue<std::string>	msg_queue;
		std::vector<int>		fds_connect_ready;

		void		accept_new_connect();
		my_socket();

	public:
		my_socket(const int port);				//Constructor
		~my_socket();

		void		init_socket();
		void		print_msg_queue();
		int			load_in_conections();
		void		read_fds();
		std::string	get_msg();
		int			get_port() const;
};

#endif
	
