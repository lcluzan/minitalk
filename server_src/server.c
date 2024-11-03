/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:58:23 by lcluzan           #+#    #+#             */
/*   Updated: 2024/11/03 17:52:04 by lcluzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static char	c;
	static int	i;
	static int	client_pid;

	(void)ucontext;
	if (client_pid == 0)
		client_pid = info->si_pid;
	c |= (sig == SIGUSR2) << i;
	if (++i >= 8)
	{
		i = 0;
		if (c == 0)
		{
			ft_putchar_fd('\n', 1);
			kill(client_pid, SIGUSR2);
			client_pid = 0;
		}
		else
		{
			ft_putchar_fd(c, 1);
			c = 0;
			kill(client_pid, SIGUSR1);
		}
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
