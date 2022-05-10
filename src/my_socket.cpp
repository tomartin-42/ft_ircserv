#include "my_socket.hpp"

my_socket::my_socket(const int port)
{
	this->data_socket.sin_family = AF_INET;
	this->data_socket.sin_addr.s_addr = INADDR_ANY;
	this->data_socket.sin_port = htons(port);
	this->data_socket_len = sizeof(data_socket);
}

void	my_socket::init_socket()
{
	this->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	bind(this->socket_fd, (struct sockaddr *) &(this->data_socket), sizeof(data_socket));
	listen(this->socket_fd, 10);
	poll_fds.push_back(pollfd());
	poll_fds.back().fd = this->socket_fd;
	poll_fds.back().events = POLLIN;
	poll((struct pollfd *) &(this->poll_fds[0]), this->poll_fds.size(), 50000);
}
