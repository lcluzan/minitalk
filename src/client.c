/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:11:18 by lcluzan           #+#    #+#             */
/*   Updated: 2024/11/01 18:15:38 by lcluzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_char(char c, pid_t pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c >>= 1;
		usleep(100);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
	{
		ft_putstr_fd("Usage: ./client [PID] [message]\n", 1);
		return (1);
	}
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
	{
		ft_send_char(av[2][i], pid);
		i++;
	}
	ft_send_char(0, pid);
	return (0);
}
