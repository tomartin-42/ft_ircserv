#ifndef _MY_SOCKET_HPP_
# define _MY_SOCKET_HPP_

#include <vector>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <queue>
#include <string>
#include <arpa/inet.h>
#include <fcntl.h>								// To fcntl function
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
		std::vector<pollfd>		poll_fds;
		struct sockaddr_in		data_socket;
		int						data_socket_len; //Need to accept function
		std::queue<std::string>	msg_queue;
		std::vector<int>		fds_open_read;


	public:
		my_socket(const int port);				//Constructor
		void		init_socket();
		void		print_msg_queue();
		int			load_in_conections();
		void		scan_fds();
		void		read_fds();
		std::string	get_msg();
		int			get_port();
		
};

#endif
	
