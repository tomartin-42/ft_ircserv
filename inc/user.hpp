/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 07:56:23 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/18 08:39:02 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _USER_HPP_
# define _USER_HPP_

#include <string>
#include <queue>

class user
{
	private:
		std::string				nick;
		std::string 			name;
		int						type;
		std::queue<std::string>	send_q;	
		std::queue<std::string>	recv_q;

	public:
		user();

		std::string	get_nick();
		std::string get_name();
		int			get_type();

		void		set_nick(std::string nick);
		void		set_name(std::string name);
		void		set_type(int type);

};

#endif
