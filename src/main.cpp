#include <sys/socket.h> // To socket
#include <netinet/in.h> // To struct sockaddr_in
#include <sys/types.h>
#include <iostream>
#include <unistd.h>
#include <cstdio>

int main(void)
{
	int		socket_fd;
	int		new_socket;
	int		enable;
	struct	sockaddr_in address;
	char	buff[1024] = {0};
	int		addrlen = sizeof(address);

	address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
//    address.sin_port = htons( PORT );
    address.sin_port = htons(4242);

	enable = 1;
	socket_fd = socket (AF_INET, SOCK_STREAM, 0);
	setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &enable, sizeof(enable));
	bind(socket_fd,(struct sockaddr *) &address, sizeof(address));
	listen (socket_fd, 10);
	new_socket = accept(socket_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
	read(new_socket, buff, 1024);
	printf("RECIBIDO = %s", buff );
//	std::cout << "RECIBIDO =" << buff << std::endl; 

}
