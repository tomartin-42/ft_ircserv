#ifndef _SERVER_HPP_
# define _SERVER_HPP_

class server
{
	public:
		unsigned int	n_connections;
		unsigned int	user_id;

	public:
		server();
		unsigned int		get_n_connections() const;
		void				add_new_connection();
		void				del_connection();
		unsigned int		get_new_user_id();

};

#endif
