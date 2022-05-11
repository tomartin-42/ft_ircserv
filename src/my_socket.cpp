#include "my_socket.hpp"

void	my_socket::scan_fds()
{
	std::vector<pollfd>::iterator	it;

	for(it = this->poll_fds.begin(); it != this->poll_fds.end(); it++)
	{
		if(it->revents & POLLIN)
		{
			if(it->fd == this->socket_fd)
			{
				int	new_fd;

				new_fd = accept(this->socket_fd, (struct sockaddr *) &(this->data_socket), (socklen_t *) &(this->data_socket_len));
				poll_fds.push_back(pollfd());
				poll_fds.back().fd = new_fd;
				poll_fds.back().events = POLLIN;
			}
		}
	}
}

my_socket::my_socket(const int port)
{
	this->data_socket.sin_family = AF_INET;
	this->data_socket.sin_addr.s_addr = INADDR_ANY;
	this->data_socket.sin_port = htons(port);
	this->data_socket_len = sizeof(data_socket);
}

void	my_socket::init_socket()
{
	int	enable; //need to enable setsockop values

	enable = 1; //need to enable setsockopt values
	this->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(this->socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &enable, sizeof(enable));
	fcntl(this->socket_fd, F_SETFL, O_NONBLOCK);
	bind(this->socket_fd, (struct sockaddr *) &(this->data_socket), sizeof(data_socket));
	listen(this->socket_fd, 10);
	poll_fds.push_back(pollfd());
	poll_fds.back().fd = this->socket_fd;
	poll_fds.back().events = POLLIN;
	poll((struct pollfd *) &(this->poll_fds[0]), this->poll_fds.size(), 50000);
	this->scan_fds();
}
