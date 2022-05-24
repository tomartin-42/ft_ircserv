#ifndef _LOG_HPP_
# define _LOG_HPP_

#include <queue>
#include <string>
#include <iostream>
#include <fstream>

class log
{
	private:
		std::queue<std::string> log;
	//	std::string				log_name;
	
	public:
		log();
		void	add_msg(const std::string msg);
		void	print_all_queue();
		void	put_in_file_queue();
};

#endif
