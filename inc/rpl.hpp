/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:45:18 by tomartin          #+#    #+#             */
/*   Updated: 2022/06/04 13:35:14 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RPL_HPP_
# define _RPL_HPP_

# define RPL_WELCOME(nick) (":Welcome to the Internet Relay Network " + nick + "\r\n")
# define RPL_YOURHOST(servername, version) (":Your host is " + servername + ", running version " + version + "\r\n")
# define RPL_MYINFO(servername, version, usr_modes, chann_modes) (":" + servername + " " + version + " " + usr_modes + " " + chann_modes + "\r\n")
# define RPL_CREATED(date) (":This server was created " + date + "\r\n")
# define RPL_BOUNCE(server_name, port) ("Try server " + server_name + ", port " + port + "\r\n")
# define RPL_NONE() ("\r\n") //300
# define RPL_USERHOST(userhost_list) (userhost_list + "\r\n") //<réponse> ::= <pseudo>['*'] '=' <'+'|'-'><hôte>
# define RPL_ISON(user_list) (user_list + "\r\n")
# define RPL_AWAY(pseudo, str) (pseudo + " " + str + "\r\n")
# define RPL_UNAWAY() (":You are no longer marked as being away\r\n")
# define RPL_NOWAWAY() (":You have been marked as being away\r\n")
# define RPL_WHOISUSER(nick, user, host, realname) (nick + " " + user + " " + host + " * :" + realname + "\r\n")
//# define RPL_WHOISSERVER(pseudo, server) (pseudo + " " + server + " :<info serveur>\r\n")
# define RPL_WHOISOPERATOR(pseudo) (pseudo + " :is an IRC operator\r\n")
# define RPL_WHOISIDLE(pseudo, idle, signon) (pseudo + " " + idle + " " + signon + " :seconds idle, signon time\r\n")
# define RPL_WHOREPLY(arg) (arg + "\r\n")
# define RPL_ENDOFWHOIS(pseudo) (pseudo + " :End of /WHOIS list\r\n")
# define RPL_WHOISCHANNELS(nick, chann_info) (nick + " :" + chann_info + "\r\n")
# define RPL_WHOWASUSER(nick, user, host, realname) (nick + " " + user + " " + host + " * :" + realname + "\r\n")
# define RPL_ENDOFWHOWAS(nick) (nick + " :End of WHOWAS\r\n")
# define RPL_LISTSTART() ("Channel :Users Name\r\n")
# define RPL_LIST(channel, topic) (channel + " :" + topic + "\r\n")
# define RPL_LISTEND() (":End of LIST\r\n")
# define RPL_CHANNELMODEIS(channel, mode, params) (channel + " " + mode + " " + params + "\r\n")
# define RPL_NOTOPIC(channel) (channel + " :No topic is set\r\n")
# define RPL_TOPIC(channel, subject) (channel + " :" + subject + "\r\n")
# define RPL_INVITING(channel, pseudo) (channel + " " + pseudo + "\r\n")
# define RPL_SUMMONING(user) (user + " :Summoning user to IRC\r\n")
# define RPL_VERSION(version, debuglevel, server, comment) (version + "." + debuglevel + " " + server + " :" + comment + "\r\n")
//# define RPL_WHOREPLY(channel, user, host, server, pseudo) (channel + " " + user + " " + host + " " + server + " " + pseudo + " <H|G>[*][@|+] :<compteur de distance> <vrai nom>\r\n")
# define RPL_ENDOFWHO(name) (name + " :End of WHO list\r\n")
# define RPL_NAMREPLY(channel, nick_list) (channel + " :" + nick_list + "\r\n") //modif_ici
# define RPL_ENDOFNAMES(channel) (channel + " :End of NAMES list\r\n")
# define RPL_LINKS(mask, server_name, hopcount, info) (mask + " " + server_name + " " + hopcount + " " + info + "\r\n")
# define RPL_ENDOFLINKS(mask) (mask + " :End of LINKS list\r\n")
# define RPL_BANLIST(mssg) (mssg + "\r\n")
# define RPL_ENDOFBANLIST(channel) (channel + " :End of list\r\n")
# define RPL_INFO(info) (":" + info + "\r\n")
# define RPL_ENDOFINFO() (":End of INFO list\r\n")
# define RPL_MOTDSTART(server) (":- " + server + " Message of the day - \r\n")
# define RPL_MOTD(comment) (":- " + comment + "\r\n")
# define RPL_ENDOFMOTD() (":End of MOTD command\r\n")
# define RPL_YOUREOPER() (":You are now an IRC operator\r\n")
# define RPL_REHASHING(config_file) (config_file + " :Rehashing\r\n")
# define RPL_TIME(server, time_serveur) (server + " :" + time_serveur + "\r\n")
# define RPL_USERSSTART() (":UserID Terminal Hôte\r\n")
//# define RPL_USERS() (":%-8s %-9s %-8s\r\n")
# define RPL_ENDOFUSERS() (":End of users\r\n")
# define RPL_NOUSERS() (":Nobody logged in\r\n")
# define RPL_TRACELINK(dest, next_serv) ("Link " + std::string(VERSION) + " " + dest + " " + next_serv + "\r\n")
# define RPL_TRACECONNECTING(classe, server) ("Try. " + classe + " " + server + "\r\n")
# define RPL_TRACEHANDSHAKE(classe, server) ("H.S. " + classe + " " + serveur + "\r\n")
# define RPL_TRACEUNKNOWN(pseudo) ("???? 1 " + pseudo + "\r\n")
# define RPL_TRACEOPERATOR(pseudo) ("Oper 1 " + pseudo + "\r\n")
# define RPL_TRACEUSER(pseudo) ("User 1 " + pseudo + "\r\n")
# define RPL_TRACESERVER(server_name) ("Serv 1 0S 0C " + server_name + " *!*@" + server_name + " V" + VERSION + "\r\n")
# define RPL_TRACENEWTYPE(new_type, name) (new_type + " 0 " + name + "\r\n")
# define RPL_TRACELOG(file_log, debug_level) ("File " + file_log + " " + debug_level + "\r\n")
# define RPL_TRACEEND(server_name, version_debug) (server_name + " " + version_debug + " :End of TRACE\r\n")
# define RPL_STATSLINKINFO(arg) (arg + "\r\n")
# define RPL_STATSCOMMANDS(arg) (arg + "\r\n")
# define RPL_STATSCLINE(host, name, port, classe) ("C " + host + " * " + name + " " + port + " " + classe + "\r\n")
# define RPL_STATSNLINE(host, name, port, classe) ("N " + host + " * " + name + " " + port + " " + classe + "\r\n")
# define RPL_STATSILINE(host, port, classe) ("I " + host + " * " + host + " " + port + " " + classe + "\r\n")
# define RPL_STATSKLINE(host, user_name, port, classe) ("K " + host + " * " + user_name + " " + port + " " + classe + "\r\n")
# define RPL_STATSYLINE(classe, frq_ping, frq_connection, sendq_max) ("Y " + classe + " " + frq_ping + " " + frq_connection + " " + sendq_max + "\r\n")
# define RPL_ENDOFSTATS(stat_letter) (stat_letter + " :End of STATS report\r\n")
# define RPL_STATSLLINE(host_mask, server_name, max_depth) ("L " + host_mask + " * " + server_name + max_depth "\r\n")
# define RPL_STATSUPTIME(arg) (":Server Up " + arg + "\r\n")
# define RPL_STATSOLINE(host_mask, name) ("O " + host_mask + " * " + name + "\r\n")
# define RPL_STATSHLINE(host_mask, server_name) ("H " + host_mask + " * " + server_name + "\r\n")
# define RPL_UMODEIS(user_mode) (user_mode + "\r\n")
# define RPL_LUSERCLIENT(int1, int2, int3) (":There are " + int1 + " users and " + int2 + " invisible on " + int3 + " servers\r\n")
# define RPL_LUSEROP(int1) (int1 + " :operator(s) online\r\n")
# define RPL_LUSERUNKNOWN(int1) (int1 + " :unknown connection(s)\r\n")
# define RPL_LUSERCHANNELS(int1) (int1 + " :channels formed\r\n")
# define RPL_LUSERME(int1, int2) (":I have " + int1 + " clients and " + int2 + " servers\r\n")
# define RPL_ADMINME(server) (server + " :Administrative info\r\n")
# define RPL_ADMINLOC1(info) (":" + info + "\r\n")
# define RPL_ADMINLOC2(info) (":" + info + "\r\n")
# define RPL_ADMINEMAIL(info) (":" + info + "\r\n")
# define RPL_CREATIONTIME(channel, c_time) (channel + " " + c_time + "\r\n")
# define RPL_YOURESERVICE(servicename) (":You are service " + servicename + "\r\n")

#endif
