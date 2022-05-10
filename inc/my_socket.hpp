#ifndef _MY_SOCKET_HPP_
# define _MY_SOCKET_HPP_

#include <vector>
#include <arpa/inet.h>
#include <fcntl.h> // To fcntl function
#include <sys/socket.h> // To socket
#include <netinet/in.h> // To struct sockaddr_in
#include <sys/types.h>
#include <poll.h> // To poll

class	my_socket
{
	private:
		int					socket_fd;
		std::vector<pollfd>	poll_fds;
		struct sockaddr_in	data_socket;
		int					data_socket_len; //Need to accept function

	public:
		my_socket(const int port);
	//	~socket();
		void	init_socket();
};

#endif
	
