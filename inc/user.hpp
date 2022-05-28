/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 07:56:23 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/28 13:39:10 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _USER_HPP_
# define _USER_HPP_

#include <string>
#include <queue>
#include "msg.hpp"
#include "connection.hpp"
#include "ft_ircserv.hpp"
#include "log.hpp"

class connection;

class user : public log
{
	private:
		unsigned int			us_id;
		const connection*		connection_p;
		std::string				nick;
		std::string 			name;
		char					type;
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
		void				set_connection_p(connection* conn_p);

		void				set_file_base_name();


};

#endif
