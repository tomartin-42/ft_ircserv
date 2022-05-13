#include "my_socket.hpp"

//Tis function return(std::string) the first msg in the queue and delete
//this element. If the queue is empty return NULL
void	my_socket::print_msg_queue()
{
	std::string	aux;
	
	while (this->msg_queue.empty() != 1)
	{
		aux = this->msg_queue.front();
		this->msg_queue.pop();
		std::cout << aux << std::endl;
	}
}

//This funcition read the fds in poll_fds ready to read and add the sring
//to msg_queue
void	my_socket::read_fds()
{
	char						buff[1024];
	int							read_len;
	std::vector<int>::iterator	it;

	for(it = this->fds_open_read.begin(); it != this->fds_open_read.end(); it++)
	{
		bzero(buff, 1023);
		read_len = read(*it, buff, 1024);
		if(read_len > 0)
			this->msg_queue.push(std::string(buff));
	}		
	
/*
	for(it = this->fds_open_read.begin(); it != this->fds_open_read.end(); it++)
	{
		//if((it->revents & POLLIN) && (it->fd != this->socket_fd))
		//{
			read(*it, buff, 1024);
			this->msg_queue.push(std::string(buff));
		//}
	}
*/
}

void	my_socket::scan_fds()
{
	std::vector<pollfd>::iterator	it;

	for(it = this->poll_fds.begin(); it != this->poll_fds.end(); it++)
	{
		if(it->revents & POLLIN)
		{
		//	if(it->fd == this->socket_fd)
		//	{
				int	new_fd;

				new_fd = accept(this->socket_fd, (struct sockaddr *) &(this->data_socket), 
						(socklen_t *) &(this->data_socket_len));
				//this->poll_fds.push_back(new_fd);
				fds_open_read.push_back(new_fd);
		//	}
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
	int	check;

	enable = 1; //need to enable setsockopt values
	this->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(this->socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &enable, sizeof(enable));
	fcntl(this->socket_fd, F_SETFL, O_NONBLOCK);
	bind(this->socket_fd, (struct sockaddr *) &(this->data_socket), sizeof(data_socket));
	listen(this->socket_fd, 10);
	poll_fds.push_back(pollfd());
	poll_fds.back().fd = this->socket_fd;
	poll_fds.back().events = POLLIN;
	while (1)
	{
		check = poll((struct pollfd *) &(this->poll_fds[0]), this->poll_fds.size(), 500);
		if(check > 0)
			this->scan_fds();
		this->read_fds();
		//std::cout << "Check = " << check << std::endl;
		print_msg_queue();
	}
}
