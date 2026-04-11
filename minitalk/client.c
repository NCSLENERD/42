/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:18:21 by nmayela           #+#    #+#             */
/*   Updated: 2026/04/10 20:18:23 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

volatile sig_atomic_t	flag;

void    send_char(char c, int pid)
{
    int bit;

    bit = 0;
    while (bit < 8)
    {
        if ((c >> bit) & 1)
            kill(pid,SIGUSR2);
        else
            kill(pid,SIGUSR1);
        bit++;
		usleep(500);
    }
	
	if (c == '\0')
	{
   		while (!flag)
        	usleep(500);
    	flag = 0;
	}
}

void	handler_ack(int sig)
{
	(void)sig;
	flag = 1;
	ft_printf("Ack recu cote client !\n");
}

void    decomp(char *s, int pid)
{
    int i;

    i = 0;
    while (s[i])
    {
        send_char(s[i], pid);
        i++;
    }
	send_char('\0', pid);
}

int main(int argc, char *argv[])
{
    int pid;
	flag = 0;
	signal(SIGUSR1,handler_ack);
    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        decomp(argv[2], pid);
    }
    return (0);
}
