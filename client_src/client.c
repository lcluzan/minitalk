/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:11:18 by lcluzan           #+#    #+#             */
/*   Updated: 2024/11/03 18:07:25 by lcluzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig)
{
	static int	received_bytes;

	if (sig == SIGUSR1)
		received_bytes++;
	else
	{
		ft_putnbr_fd(received_bytes, 1);
		ft_putstr_fd(" bytes received\n", 1);
		exit(EXIT_SUCCESS);
	}
}

void	send_char(char c, pid_t pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
		++i;
	}
}

void	send_str(char *s, pid_t pid)
{
	int	i;

	i = 0;
	while (s[i])
	{
		send_char(s[i], pid);
		++i;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr_fd("Usage: ./client [PID] [message]\n", 1);
		return (EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	send_str(av[2], pid);
	send_char(0, pid);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
