/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 02:19:03 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/13 17:38:56 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"

static volatile sig_atomic_t	g_ack_received = 0;

static void	ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

static void	send_char(int server_pid, char c)
{
	t_uint	i;

	i = 0;
	while (i < 8)
	{
		g_ack_received = 0;
		if (c & (1 << i))
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		while (!g_ack_received)
			pause();
		i++;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	int					server_pid;
	char				*str;

	if (argc != 3)
		return (0);
	sa.sa_flags = 0;
	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	server_pid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str)
		send_char(server_pid, *str++);
	send_char(server_pid, '\0');
	return (0);
}
