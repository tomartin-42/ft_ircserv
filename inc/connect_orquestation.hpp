/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_orquestation.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:39:20 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/18 13:16:46 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONNECT_ORQUESTATION_HPP_
# define _CONNECT_ORQUESTATION_HPP_

#include "ft_ircserv.hpp"
#include "connection.hpp"
#include <vector>
#include <poll.h>

class connect_orquestation
{
	private:
		pollfd					poll_fd[MAX_CONNECTIONS];
		std::vector<connection>	l_connections;

	public:
		void	add_connection(connection &new_connect);
		int		poll_connections();
		void	search_to_send();
		void	search_to_recv();
};

#endif
