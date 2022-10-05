/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sending.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:31:18 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/15 17:30:30 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SENDING_HPP_
# define _SENDING_HPP_

#include <vector>
#include <poll.h>
#include <string>
#include <sys/socket.h>

class sending
{
	private:
		std::vector<pollfd>	poll_fds;
		std::vector<int>	fds_ready;
		std::vector<pollfd> poll_fd;

	public:
    	int	send_singel_msg(int fd, std::string msg);
};

#endif
