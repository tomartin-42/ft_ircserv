#ifndef _MSG_HPP_
# define _MSG_HPP_

#include <queue>
#include <string>
#include <iostream>

class msg
{
	private:
		std::queue<std::string>	msg_q;
	
	public:
		~msg();
		bool		check_if_empty() const;
		int			number_msg() const;
		void		add_msg(const char* str);
		void		add_msg(const std::string str);
		std::string	extract_msg();
		const char*	extract_msg_to_char();
		void		print_all_msg();
};

#endif

