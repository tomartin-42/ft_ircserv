/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 07:56:23 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/18 11:44:51 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _USER_HPP_
# define _USER_HPP_

#include <string>
#include <queue>
#include "ft_ircserv.hpp"

class user
{
	private:
		int						us_id;
		std::string				nick;
		std::string 			name;
		char					type;
		std::queue<std::string>	send_q;	
		std::queue<std::string>	recv_q;
		//std::vector<chanel>		chanel_list;

	public:
		user();

		std::string&	get_nick();
		std::string&	get_name();
		char&			get_type();

		void		set_nick(const std::string& nick);
		void		set_name(const std::string& name);
		void		set_type(const char& type);

};

#endif
