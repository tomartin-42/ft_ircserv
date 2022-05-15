/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:35:01 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/15 20:48:19 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.hpp"
#include "sending.hpp"
#include <iostream>

int main(void)
{
	std::string	msg("SERVER test.Ateam.es 1 : Experimental server");
	my_socket new_socket(4242);
	sending		test;

	new_socket.init_socket();
	while(1)
	{
		new_socket.load_in_conections();
		new_socket.scan_fds();
		new_socket.read_fds();
		new_socket.print_msg_queue();
		sleep(15);
		std::cout << "YAAAA\n";
		test.send_singel_msg(4, msg);
	}
}
