/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:21:34 by nmayela           #+#    #+#             */
/*   Updated: 2026/01/19 17:21:37 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

/*char *get_next_line(int fd)
{
 
}*/

int main()
{
    char* name = "test.txt";

    int fd = open(name, O_RDWR);

    if(fd ==-1) printf("Erreur\n");
    else printf("Succes name : %s nb :%d \n",name,fd);

    char buffer[1];
    char buffer2[1024] = "";
    int i = 0;
    int nb = read(fd , buffer,1);
    while(buffer[0] != '\n' && nb > 0)
    {
        buffer2[i] = buffer[0];
        i++;
        nb = read(fd , buffer,1);
    }
    buffer2[i] = '\n';
    printf("Le fichier contient : %s",buffer2);
    //printf("Le fichier contient : %c\n",buffer[i-1]);
    printf("Taille : %d\n",nb);
    //printf("Buffer : %s",buffer);
}

// Faire un premier read 