/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ircserv.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:13:09 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/02 11:15:27 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_IRCSERV_HPP
# define _FT_IRCSERV_HPP

#include <string>

#define	HOST_NAME	"irc.teamA.com"
#define	MAX_CONNECTIONS	128

//----------------Send o Recv-------------------//

#define SEND 0
#define RECV 1

//---------------Types users--------------------//

#define UNKNOW 'U'
#define OPERATOR 'O'


//--------------Template functions----------------//

template<class T>
std::string itoa(T a)
{
	std::string ss = "";   //create empty string
    while(a)
    {
        int x = a%10;
        a /= 10;
        char i = '0';
        i = i + x;
        ss = i + ss;      //append new character at the front of the string!
    }
    return ss;
}

#endif
