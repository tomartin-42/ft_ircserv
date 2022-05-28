/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:52:14 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/28 12:07:59 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.hpp"

void	log::add_msg(const std::string& msg, const std::string& head)
{
	this->log_list.push(head + "->" + msg);
}

void	log::print_all_queue()
{
	std::queue<std::string>	aux(this->log_list);

	while(!aux.empty())
	{
		std::cout << aux.front() << std::endl;
		aux.pop();
	}
}

const std::string	log::get_file_base_name()
{
	return (this->file_base_name);
}

void log::put_in_file_queue()
{
	std::queue<std::string>	aux(this->log_list);
	std::ofstream file;
	std::string	s_file;

	s_file = this->get_file_base_name() + ".log";
	
	file.open(s_file.c_str(), std::ios::trunc);
	while(!aux.empty())
	{
		file << aux.front() << std::endl;
		aux.pop();
	}
	file.close();
}
	
