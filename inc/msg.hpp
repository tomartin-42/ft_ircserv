/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:01:05 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/30 13:33:12 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MSG_HPP_
# define _MSG_HPP_

#include <queue>
#include <string>
#include <iostream>

class msg
{
	private:
		std::queue<std::string>	msg_q;
		std::string				buff_aux;
	
		std::string	get_next_msg();
	public:
		~msg();
		bool		check_if_empty() const;
		int			number_msg() const;
		void		add_msg(const char* str);
		void		add_msg(const std::string str);
		std::string	extract_msg();
		void		print_all_msg();
		int			msg_q_size();
		int			msg_front_len();
		void		pop_msg();
};

#endif

