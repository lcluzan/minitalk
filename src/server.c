/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:58:23 by lcluzan           #+#    #+#             */
/*   Updated: 2024/11/02 16:33:38 by lcluzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signum)
{
	static char	c = 0;
	static int	i = 0;

	c += (signum == SIGUSR1) << i;
	if (++i == 8)
	{
		if (c == 0)
		{
			ft_putchar_fd('\n', 1);
			i = 0;
		}
		else
		{
			ft_putchar_fd(c, 1);
			i = 0;
			c = 0;
		}
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 1)
	{
		ft_putstr_fd("Usage: ./server\n", 1);
		return (1);
	}
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	signal_1(SIGUSR1, ft_handler);
	signal_2(SIGUSR2, ft_handler);
	while (1)
		pause();
	return (0);
}
