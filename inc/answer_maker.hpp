/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer_maker.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:55:04 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/03 12:24:17 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ANSWER_MAKER_HPP_
# define _ANSWER_MAKER_HPP_

#include "rpl.hpp"

class answer_maker
{
	private:
		int			code;
		std::string	arg1;
		std::string	arg2;
		std::string	arg3;
		std::string	arg4;
		
	public:
		answer_maker(int cde, std::string ar1, std::string ar2, std::string ar3, std::string ar4);
		std::string	answ(int cde);
};

