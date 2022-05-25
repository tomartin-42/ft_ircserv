/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_orquestation.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:39:20 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/23 11:44:44 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONNECT_ORQUESTATION_HPP_
# define _CONNECT_ORQUESTATION_HPP_

#include "ft_ircserv.hpp"
#include "connection.hpp"
#include "user.hpp"
#include "poll_fd.hpp"
#include <cstdio>
#include <vector>
#include <poll.h>
#include <iostream>

class connect_orquestation
{
	private:
		std::vector<connection>	l_connections;
		std::vector<user>		l_user;
		poll_fd					poll_list;
		
		void	search_to_send();
		void	search_to_recv();

	public:
		void	add_connection(connection &new_connect);
		int		poll_connections();
		void	init_ref_pollfd();
		void	check_connection_status();
		void	gestion_communication();
		void	print_msgs();
		void	add_user(user& new_user);
};

#endif
