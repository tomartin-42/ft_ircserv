#include "my_socket.hpp"

//Tis function return(std::string) the first msg in the queue and delete
//this element. If the queue is empty return NULL
std::string	my_socket::get_msg()
{
	std::string	aux;
	
	if(msg_queue.empty())
		return NULL;
	aux = this->msg_queue.front();
	this->msg_queue.pop();
	return aux;
}

//This funcition read the fds in poll_fds ready to read and add the sring
//to msg_queue
void	my_socket::read_fds()
{
	char	buff[1024];
	std::vector<pollfd>::iterator	it;

	for(it = this->poll_fds.begin(); it != this->poll_fds.end(); it++)
	{
		if((it->revents & POLLIN) && (it->fd != this->socket_fd))
		{
			read(it->fd, buff, 1024);
			this->msg_queue.push(std::string(buff));
		}
	}
}

void	my_socket::scan_fds()
{
	std::vector<pollfd>::iterator	it;

	for(it = this->poll_fds.begin(); it != this->poll_fds.end(); it++)
	{
		std::cout << "HOLA " << poll_fds.size() << it->revents << std::endl;
		if(it->revents & POLLIN)
		{
			if(it->fd == this->socket_fd)
			{
				int	new_fd;

				std::cout << "HOLA2\n";
				new_fd = accept(this->socket_fd, (struct sockaddr *) &(this->data_socket), 
						(socklen_t *) &(this->data_socket_len));
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
	this->read_fds();
}
