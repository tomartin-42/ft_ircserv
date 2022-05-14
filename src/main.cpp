#include "my_socket.hpp"

int main(void)
{
	my_socket new_socket(4242);

	new_socket.init_socket();
	while(1)
	{
		new_socket.load_in_conections();
		new_socket.scan_fds();
		new_socket.read_fds();
		new_socket.print_msg_queue();
	}
}
