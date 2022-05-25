/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:35:01 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/25 11:22:48 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.hpp"
#include "connect_orquestation.hpp"
#include "connection.hpp"
#include "server.hpp"
#include <iostream>
#include <cstdio>

int main(void)
{
	server					new_server;
	my_socket 				new_socket(4242);
	connect_orquestation	connect_orquest;

	new_socket.init_socket();
	while(1)
	{
		new_socket.load_in_connections();
		while(new_socket.pending_connection())
		{
			connection in_connect(new_socket.extract_new_connection());
			in_connect.c_user.set_us_id(new_server.get_new_user_id()); //with user class public
			//in_connect.set_c_user_id(new_server.get_new_user_id()); //Dual seter
			connect_orquest.add_connection(in_connect);
		}
		connect_orquest.gestion_communication();
		connect_orquest.print_msgs();
	}
}
