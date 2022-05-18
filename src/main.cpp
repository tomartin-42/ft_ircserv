/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:35:01 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/18 10:00:34 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_socket.hpp"
#include "connect_orquestation.hpp"
#include "connection.hpp"
#include <iostream>
#include <cstdio>

int main(void)
{
	my_socket 				new_socket(4242);
	connect_orquestation	connect_orquest;

	new_socket.init_socket();
	while(1)
	{
		if(new_socket.pending_connection())
			connection in_connect(new_socket.extract_new_connection());
	}
}
