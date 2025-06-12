/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:31:19 by prambaud          #+#    #+#             */
/*   Updated: 2025/06/03 11:28:18 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "webserv.hpp"

void launch_servers(std::vector<t_serveur>& servers)
{
	std::cout << "---- SERVER INIT ----" << std::endl << std::endl;
    int status;

	for (size_t i = 0; i < servers.size(); ++i)
    {
		// creation du socket serveur
		servers[i].socket = server_socket_creation(&servers[i]); // bind + socket_serveur
		if (servers[i].socket == -1) {
			std::cerr << "[Server] Creation error: " << strerror(errno) << std::endl;
			return ;
		}
//		std::cout << "socket server[" << i << "] :" << servers[i].socket << std::endl;

		// Listen du PORT via la socket
		std::cout << "[Server] Listening on port " << servers[i].port << std::endl << std::endl;
		status = listen(servers[i].socket, BACKLOG);
		if(status != 0) {
			std::cerr << "[Server] Listen error: " << strerror(errno) << std::endl;
			return ;
		}
	}
}

int main(int ac, char **av)
{
    if (ac != 2) {
		std::cerr << "Wrong input" << std::endl;
		return 1;
	}
	std::ifstream	configFile(av[1]);
	if (!configFile.is_open()) {
		std::cerr << "Cannot open file" << std::endl;
		return 1;
	}
	sighandler_init();
    std::vector<t_serveur> data_config;
	try
	{
		ft_configFileparsing(configFile, data_config);
		configFile.close();
		//printDataConfig(data_config);
		launch_servers(data_config);
		waiting_connection(data_config);
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::vector<t_serveur>::iterator	it = data_config.begin();
	while (it != data_config.end())
	{
		if (it->socket != -1)
			close(it->socket);
		++it;
	}
    return (0);
}
