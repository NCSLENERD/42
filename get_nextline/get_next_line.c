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
#include "get_next_line.h"

int	verif_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(char *buffer)
{
	int	i;
	char *stock;

	stock = malloc(sizeof(char) * BUFFER_SIZE);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		{
			stock[i] = buffer[i];
			i++;
		}
		stock[i] = '\n';
		return(stock);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stock;
	//char		*line;
	int			i;

	buffer = malloc (sizeof(char) * BUFFER_SIZE);
	stock = malloc(sizeof(char) * BUFFER_SIZE);// faire fonction auxiliaire ou utiliser strjoin car ca free le stock 
	read(fd, buffer, BUFFER_SIZE);

	i = 0;
	//remplacer par un strjoin ?
	while (buffer[i])
		{
			stock[i] = buffer[i];
			i++;
		}
	free(buffer);
	if(verif_line(stock) == 1)
	{
		return(get_line(stock));
		/*line = get_line(stock);
		return(line);*/
	}
	return(stock);
}

int main()
{
    char* name = "test.txt";

    int fd = open(name, O_RDWR);
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
}
// Faire un premier read 