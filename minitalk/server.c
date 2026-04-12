/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 02:07:16 by nmayela           #+#    #+#             */
/*   Updated: 2026/04/04 02:07:17 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static int		bits;
	static char		c;
	pid_t			sender_pid;

	(void)context;
	sender_pid = info->si_pid;
	if (sig == SIGUSR2)
		c |= (1 << bits);
	bits++;
	if (bits == 8)
	{
		if (c == '\0')
			kill(sender_pid, SIGUSR1);
		else
			write(1, &c, 1);
		bits = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
