/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:30:37 by dimolin2          #+#    #+#             */
/*   Updated: 2023/01/26 17:30:39 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	ft_server_response(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_putstr_fd("The server has printed the message successfully!\n", 1);
		exit(0);
	}
}

int	ft_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_errors(char *msg)
{
	int	pid;

	pid = ft_atoi(msg);
	if (pid <= 0 || ft_is_num(msg) != 1)
	{
		ft_putstr_fd("error: invalid pid\n", 1);
		return (-1);
	}
	else
		return (1);
}

void	ft_send_msg_bit(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		i++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*message;

	if (argc != 3)
	{
		ft_putstr_fd("error: invalid arguments\n", 1);
		return (-1);
	}
	if (ft_errors(argv[1]) != 1)
		return (-1);
	pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	signal(SIGUSR1, ft_server_response);
	while (message[i] != '\0')
	{
		ft_send_msg_bit(message[i], pid);
		i++;
	}
	ft_send_msg_bit(message[i], pid);
	pause();
	return (0);
}
