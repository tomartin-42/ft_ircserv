/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer_maker.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:10:19 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/03 12:24:20 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "answer_maker.hpp"

answer_maker::answer_maker(std::string ar1, std::string ar2, std::string ar3, std::string ar4) :
   arg1(ar1), arg2(ar2), arg3(ar3), arg4(ar4), sample(HOST_NAME) {}	

std::string answer_maker::answ(int cde)
{
	std::string code(generate_code(cde));

	switch (cde)
	{
		case 1:
			return this->sample + code + RPL_WELCOME(arg1);
		case 2:
			return this->sample + code + RPL_YOURHOST(arg1, arg2);
		case 3:
			return this->sample + code + RPL_CREATED(arg1);
		case 4:
			return this->sample + code + RPL_MYINFO(arg1, arg2, arg3, arg4);
		case 5:
			return this->sample + code + RPL_BOUNCE(arg1, arg2);
		case 200:
			return this->sample + code + RPL_TRACELINK(arg1, arg2);
		case 203:
			return this->sample + code + RPL_TRACEUNKNOWN(arg1);
		case 204:
			return this->sample + code + RPL_TRACEOPERATOR(arg1);
		case 205:
			return this->sample + code + RPL_TRACEUSER(arg1);
		case 206:
			return this->sample + code + RPL_TRACESERVER(arg1);
		case 211:
			return this->sample + code + RPL_STATSLINKINFO(arg1);
		case 212:
			return this->sample + code + RPL_STATSCOMMANDS(arg1);
		case 219:
			return this->sample + code + RPL_ENDOFSTATS(arg1);
		case 221:
			return this->sample + code + RPL_UMODEIS(arg1);
		case 242:
			return this->sample + code + RPL_STATSUPTIME(arg1);
		case 251:
			return this->sample + code + RPL_LUSERCLIENT(arg1, arg2, arg3);
		case 252:
			return this->sample + code + RPL_LUSEROP(arg1);
		case 253:
			return this->sample + code + RPL_LUSERUNKNOWN(arg1);
		case 254:
			return this->sample + code + RPL_LUSERCHANNELS(arg1);
		case 255:
			return this->sample + code + RPL_LUSERME(arg1, arg2);
		case 256:
			return this->sample + code + RPL_ADMINME(arg1);
		case 257:
			return this->sample + code + RPL_ADMINLOC1(arg1);
		case 258:
			return this->sample + code + RPL_ADMINLOC2(arg1);
		case 259:
			return this->sample + code + RPL_ADMINEMAIL(arg1);
		case 262:
			return this->sample + code + RPL_TRACEEND(arg1, arg2);
		case 301:
			return this->sample + code + RPL_AWAY(arg1, arg2);
		case 302:
			return this->sample + code + RPL_USERHOST(arg1);
		case 303:
			return this->sample + code + RPL_ISON(arg1);
		case 305:
			return this->sample + code + RPL_UNAWAY();
		case 306:
			return this->sample + code + RPL_NOWAWAY();
		case 311:
			return this->sample + code + RPL_WHOISUSER(arg1, arg2, arg3, arg4);
		case 313:
			return this->sample + code + RPL_WHOISOPERATOR(arg1);
		case 314:
			return this->sample + code + RPL_WHOWASUSER(arg1, arg2, arg3, arg4);
		case 315:
			return this->sample + code + RPL_ENDOFWHO(arg1);
		case 317:
			return this->sample + code + RPL_WHOISIDLE(arg1, arg2, arg3);
		case 318:
			return this->sample + code + RPL_ENDOFWHOIS(arg1);
		case 319:
			return this->sample + code + RPL_WHOISCHANNELS(arg1, arg2);
		case 322:
			return this->sample + code + RPL_LIST(arg1, arg2);
		case 323:
			return this->sample + code + RPL_LISTEND();
		case 324:
			return this->sample + code + RPL_CHANNELMODEIS(arg1, arg2, arg3);
		case 329:
			return this->sample + code + RPL_CREATIONTIME(arg1, arg2);
		case 332:
			return this->sample + code + RPL_TOPIC(arg1, arg2);
		case 341:
			return this->sample + code + RPL_INVITING(arg1, arg2);
		case 351:
			return this->sample + code + RPL_VERSION(arg1, arg2, arg3, arg4);
		case 352:
			return this->sample + code + RPL_WHOREPLY(arg1);
		case 353:
			return this->sample + code + RPL_NAMREPLY(arg1, arg2);
		case 364:
			return this->sample + code + RPL_LINKS(arg1, arg2, arg3, arg4);
	}
	return std::string("");
}

std::string	answer_maker::generate_code(int i) const
{
	if(i < 10)
		return std::string("00" + itoa(i));
	else if(i < 100)
		return std::string("0" + itoa(i));
	return std::string(itoa(i));
}
