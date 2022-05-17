/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:35:01 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/16 19:39:54 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.hpp"
#include "sending.hpp"
#include <iostream>
#include <cstdio>

int main(void)
{
	std::string	msg("SERVER test.Ateam.es 1 : Experimental server");
	my_socket new_socket(4242);
	sending		test;
	char		buff[512];

	new_socket.init_socket();
	while(1)
	{
		new_socket.load_in_conections();
		new_socket.read_fds();
		new_socket.print_msg_queue();
		sleep(2);
		send(4, &msg[0], msg.size(), MSG_DONTWAIT);
		sleep(10);
		recv(4, &buff, 512, MSG_DONTWAIT);
		printf("-- %s --\n", buff);
	}
}
