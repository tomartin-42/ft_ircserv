/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_orquestation.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:39:20 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/28 13:34:52 by tomartin         ###   ########.fr       */
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
#include <map>
#include <utility>
#include <poll.h>
#include <iostream>

typedef std::pair<user, connection>	us_con;

class connect_orquestation
{
	private:
		std::map<int, std::pair<user, connection> >	l_connections;
		poll_fd											poll_list;
		
		void	search_to_send();
		void	search_to_recv();

	public:
		void	add_connection(user& new_user, connection& new_connect);
		int		poll_connections();
		void	init_ref_pollfd();
		void	check_connection_status();
		void	gestion_communication();
		void	print_msgs();
};

#endif
