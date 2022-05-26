/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:52:11 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/26 11:38:11 by tomartin         ###   ########.fr       */
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
		unsigned int			log_name;
	
	public:
		log();
		log(unsigned int log_name);

		unsigned int	get_log_name() const;
		void			add_msg(const std::string& msg);
		void			print_all_queue();
		void			put_in_file_queue();
};

#endif
