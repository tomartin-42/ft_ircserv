#include "server.hpp"

server::server() : n_connections(0), user_id(0) {}

unsigned int server::get_n_connections() const
{
	return (this->n_connections);
}

void	server::add_new_connection()
{
	this->n_connections += 1;
}

void	server::del_connection() //subtraction a conter of connections
{
	this->n_connections -= -1;
}

unsigned int	server::get_new_user_id()
{
	unsigned int	aux;
	
	aux = this->user_id;
	this->user_id += 1;
	return (aux);
}
