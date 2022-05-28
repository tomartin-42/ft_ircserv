/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:52:11 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/28 12:07:56 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LOG_HPP_
# define _LOG_HPP_

#include <queue>
#include <string>
#include <iostream>
#include <fstream>
#include "ft_ircserv.hpp"

class log
{
	private:
		std::queue<std::string> log_list;
	protected:
		std::string				file_base_name;
	
	public:
		void				add_msg(const std::string& msg, const std::string& head);
		void				print_all_queue();
		const std::string	get_file_base_name();
		virtual void		set_file_base_name() = 0; //seter to get file name;
		void				put_in_file_queue();
};

#endif
