#include "msg.hpp"

bool	msg::check_if_empty() const
{
	if(this->msg_q.empty())
		return true;
	return false;
}

void	msg::add_msg(const char* str)
{
	this->msg_q.push(std::string(str));
}

void	msg::add_msg(const std::string str)
{
	this->msg_q.push(str);
}

std::string	msg::extract_msg()
{
	std::string	aux;

	aux = this->msg_q.front();
	this->msg_q.pop();
	return aux;
}

const char*	msg::extract_msg_to_char()
{
	std::string	aux;

	aux = this->msg_q.front();
	this->msg_q.pop();
	return aux.c_str();
}

int	msg::number_msg() const
{
	return msg_q.size();
}

msg::~msg()
{
	while(!this->msg_q.empty())
		this->msg_q.pop();
}
