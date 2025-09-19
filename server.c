/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 03:17:36 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/19 00:37:17 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "ft_printf.h"

static void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static char	c[2];

	(void)context;
	if (sig == SIGUSR2)
		c[0] |= (1 << c[1]);
	c[1]++;
	if (c[1] == 8)
	{
		if (c[0] == '\0')
			write(1, "\n", 1);
		else
			write(1, c, 1);
		c[0] = 0;
		c[1] = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("%d\n", getpid());
	while (1)
		pause();
	return (0);
}
