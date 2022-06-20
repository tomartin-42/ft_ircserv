/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer_maker.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:10:19 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/04 13:33:06 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "answer_maker.hpp"

answer_maker::answer_maker(std::string ar1, std::string ar2, std::string ar3, std::string ar4) :
   arg1(ar1), arg2(ar2), arg3(ar3), arg4(ar4), head(HOST_NAME) {}	

std::string answer_maker::answ(int cde)
{
	switch (cde)
	{
		case 1:
			return std::string(this->head + RPL_WELCOME(arg1));
		case 2:
			return std::string(this->head + RPL_YOURHOST(arg1, arg2));
		case 3:
			return std::string(this->head + RPL_CREATED(arg1));
		case 4:
			return std::string(this->head + RPL_MYINFO(arg1, arg2, arg3, arg4));
		case 5:
			return std::string(this->head + RPL_BOUNCE(arg1, arg2));
		case 200:
			return std::string(this->head + RPL_TRACELINK(arg1, arg2));
		case 203:
			return std::string(this->head + RPL_TRACEUNKNOWN(arg1));
		case 204:
			return std::string(this->head + RPL_TRACEOPERATOR(arg1));
		case 205:
			return std::string(this->head + RPL_TRACEUSER(arg1));
		case 206:
			return std::string(this->head + RPL_TRACESERVER(arg1));
		case 211:
			return std::string(this->head + RPL_STATSLINKINFO(arg1));
		case 212:
			return std::string(this->head + RPL_STATSCOMMANDS(arg1));
		case 219:
			return std::string(this->head + RPL_ENDOFSTATS(arg1));
		case 221:
			return std::string(this->head + RPL_UMODEIS(arg1));
		case 242:
			return std::string(this->head + RPL_STATSUPTIME(arg1));
		case 251:
			return std::string(this->head + RPL_LUSERCLIENT(arg1, arg2, arg3));
		case 252:
			return std::string(this->head + RPL_LUSEROP(arg1));
		case 253:
			return std::string(this->head + RPL_LUSERUNKNOWN(arg1));
		case 254:
			return std::string(this->head + RPL_LUSERCHANNELS(arg1));
		case 255:
			return std::string(this->head + RPL_LUSERME(arg1, arg2));
		case 256:
			return std::string(this->head + RPL_ADMINME(arg1));
		case 257:
			return std::string(this->head + RPL_ADMINLOC1(arg1));
		case 258:
			return std::string(this->head + RPL_ADMINLOC2(arg1));
		case 259:
			return std::string(this->head + RPL_ADMINEMAIL(arg1));
		case 262:
			return std::string(this->head + RPL_TRACEEND(arg1, arg2));
		case 301:
			return std::string(this->head + RPL_AWAY(arg1, arg2));
		case 302:
			return std::string(this->head + RPL_USERHOST(arg1));
		case 303:
			return std::string(this->head + RPL_ISON(arg1));
		case 305:
			return std::string(this->head + RPL_UNAWAY());
		case 306:
			return std::string(this->head + RPL_NOWAWAY());
		case 311:
			return std::string(this->head + RPL_WHOISUSER(arg1, arg2, arg3, arg4));
		case 313:
			return std::string(this->head + RPL_WHOISOPERATOR(arg1));
		case 314:
			return std::string(this->head + RPL_WHOWASUSER(arg1, arg2, arg3, arg4));
		case 315:
			return std::string(this->head + RPL_ENDOFWHO(arg1));
		case 317:
			return std::string(this->head + RPL_WHOISIDLE(arg1, arg2, arg3));
		case 318:
			return std::string(this->head + RPL_ENDOFWHOIS(arg1));
		case 319:
			return std::string(this->head + RPL_WHOISCHANNELS(arg1, arg2));
		case 322:
			return std::string(this->head + RPL_LIST(arg1, arg2));
		case 323:
			return std::string(this->head + RPL_LISTEND());
		case 324:
			return std::string(this->head + RPL_CHANNELMODEIS(arg1, arg2, arg3));
		case 329:
			return std::string(this->head + RPL_CREATIONTIME(arg1, arg2));
		case 332:
			return std::string(this->head + RPL_TOPIC(arg1, arg2));
		case 341:
			return std::string(this->head + RPL_INVITING(arg1, arg2));
		case 351:
			return std::string(this->head + RPL_VERSION(arg1, arg2, arg3, arg4));
		case 352:
			return std::string(this->head + RPL_WHOREPLY(arg1));
		case 353:
			return std::string(this->head + RPL_NAMREPLY(arg1, arg2));
		case 364:
			return std::string(this->head + RPL_LINKS(arg1, arg2, arg3, arg4));
	}
	return std::string("");
}

