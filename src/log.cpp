#include "log.hpp"

//log::log() : log_name(user_id)

void	log::add_msg(const std::string& msg)
{
	this->log.push(msg)
}

void	log::print_all_queue()
{
	std::queue<std::string>	aux(this->log);

	while(!this->aux.empty())
	{
		std::cout << aux.begin();
		aux.pop();
	}
}

void msg::put_in_file_queue()
{
	std::queue<std::string>	aux(this->log);
	std::ofstream file;
	
	file.open(
}
	
