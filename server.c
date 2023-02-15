/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:30:45 by dimolin2          #+#    #+#             */
/*   Updated: 2023/01/26 17:30:46 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0 && power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

static void	ft_message(int signal, siginfo_t *info, void *context)
{
	static int	current_bit = 0;
	static int	char_val = 0;
	static int	client_pid = 0;

	client_pid = info->si_pid;
	(void)context;
	if (signal == SIGUSR1)
		char_val += ft_recursive_power(2, current_bit);
	if (current_bit == 7)
	{
		if (char_val == 0)
		{
			ft_putchar_fd('\n', 1);
			current_bit = 0;
			char_val = 0;
			kill(client_pid, SIGUSR1);
		}
		write(1, &char_val, 1);
		current_bit = 0;
		char_val = 0;
		return ;
	}
	current_bit++;
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	ft_putstr_fd("server pid: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_message;
	while (1)
	{
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
	}
}
