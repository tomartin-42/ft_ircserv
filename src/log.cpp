/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:52:14 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/26 11:34:22 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.hpp"

log::log() {}

log::log(unsigned int name) : log_name(name) {}

unsigned int	log::get_log_name() const
{
	return (this->log_name);
}

void	log::add_msg(const std::string& msg)
{
	std::string	aux;

	aux = itoa(this->get_log_name()) + "->" + msg;
	this->log_list.push(aux);
}

void	log::print_all_queue()
{
	std::queue<std::string>	aux(this->log_list);

	while(!aux.empty())
	{
		std::cout << aux.front();
		aux.pop();
	}
}

void log::put_in_file_queue()
{
	std::queue<std::string>	aux(this->log_list);
	std::ofstream file;
	std::string	s_file;

	s_file = "log" + itoa(this->get_log_name()) + "txt";
	
	file.open(s_file.c_str(), std::ios::trunc);
	while(!aux.empty())
	{
		file << this->get_log_name() << "->" << aux.front() << std::endl;
		aux.pop();
	}
	file.close();
}
	
