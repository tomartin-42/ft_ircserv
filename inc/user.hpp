/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 07:56:23 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/26 09:51:42 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _USER_HPP_
# define _USER_HPP_

#include <string>
#include <queue>
#include "ft_ircserv.hpp"
#include "connection.hpp"
#include "log.hpp"


class user : public log
{
	private:
		unsigned int			us_id;
		const connection*		connection_p;
		std::string				nick;
		std::string 			name;
		char					type;
		std::queue<std::string>	send_q;	
		std::queue<std::string>	recv_q;
		//std::vector<chanel>	chanel_list;

	public:
		user(unsigned int id);

		std::string		get_nick() const;
		std::string		get_name() const;
		char			get_type() const;

		void				set_nick(const std::string& nick);
		void				set_name(const std::string& name);
		void				set_type(const char& type);
		void				set_us_id(const unsigned int& serv_id);
		const connection*	get_connection_p();
		void				set_connection_p(const connection* conn_p);
};

#endif
