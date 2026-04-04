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
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
/*Côté serveur — c'est lui qui reconstruit le caractère bit par bit.

Serveur → reçoit les signaux → reconstruit les bits → affiche le caractère
Client → lit le string → extrait les bits → envoie les signaux */
int	handler(int sig)
{
    static int      bits;    // compteur de bits reçus
    static char     c;       // caractère en cours de reconstruction

	if (SIGUSR2 == sig)
		c |= 1 << i ;
    // décaler c d'un bit vers la gauche
    // si sig == SIGUSR2 → mettre le bit à 1
    // si on a reçu 8 bits → afficher c et reset
}

int main(void)
{
    // afficher le PID
	printf("%d\n",getpid());
    // attendre des signaux
	while(1)
		pause();
	signal(SIGUSR1,handler(SIGUSR1));
}
