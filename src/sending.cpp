/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sending.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:17:47 by tomartin          #+#    #+#             */
/*   Updated: 2022/05/15 17:39:19 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sending.hpp"

int	sending::send_singel_msg(int fd, std::string msg)
{
	pollfd	pollset;
	int		check;

	pollset.fd = fd;
	pollset.events = POLLOUT;
	check = poll(&pollset, 1, 500);
	if(check > 0)
		send(fd, (char *)&(msg[0]), msg.size(), MSG_DONTWAIT);
	return 0;
}			
