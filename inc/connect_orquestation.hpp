/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_orquestation.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:39:20 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/20 09:37:48 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONNECT_ORQUESTATION_HPP_
# define _CONNECT_ORQUESTATION_HPP_

#include "ft_ircserv.hpp"
#include "connection.hpp"
#include <vector>
#include <poll.h>
#include <iostream>

class connect_orquestation
{
	private:
		std::vector<connection>	l_connections;
		std::vector<pollfd>		ref_pollfd;

		void	search_to_send();
		void	search_to_recv();
	public:
		void	add_connection(connection &new_connect);
		int		poll_connections();
		void	init_ref_pollfd();
		void	check_connection_status();
		void	gestion_communication();
};

#endif
