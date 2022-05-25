#include "log.hpp"

log::log(unsigned int user_id) : log_name(user_id) {}

void	log::add_msg(const std::string& msg)
{
	this->log_list.push(msg);
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
/*
void msg::put_in_file_queue()
{
	std::queue<std::string>	aux(this->log);
	std::ofstream file;
	
	file.open(
}
*/	
