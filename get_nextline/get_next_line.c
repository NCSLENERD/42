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

int	verif_line(char *buffer) // vérifie si on a trouver un \n
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

	i = 0;
	while (buffer[i] != '\n' && buffer[i])//Calcul de la taille de la ligne
			i++;
	stock = malloc((sizeof(char) * i) + 1);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		{
			stock[i] = buffer[i];
			i++;
		}
		stock[i] = '\n';
		return(stock);
}

char *clear(char *str)
{
	char	*res;
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(str);
	i = 0;
	while (str[i] != '\n' && str[i])//Calcul de la taille de la ligne
			i++;
	i++;
	res = malloc(sizeof(char) * (len - i));
	j = 0;
	while(str[i])
	{
		res[j] = str[i];
		j++;
		i++;
	}
	return(res);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stock;
	char		*line;
	char		*tmp;
	int			r;


	while (1)
    {
		buffer = malloc (sizeof(char) * BUFFER_SIZE + 1);
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == 0)
		{
    		free(buffer);
    		break;
		}
		if(r == -1){
			free(buffer);
			return (NULL);
		}
		buffer[r] = '\0'; // demander a riwan si \0 necessaire
        tmp = ft_strjoin(stock, buffer);
        free(stock);
		free(buffer);
        stock = tmp;

        
        if (verif_line(stock) == 1)
            break;
    }

	if (!stock || *stock == '\0')
    	return (NULL);

	/*buffer = malloc (sizeof(char) * BUFFER_SIZE);
	r = read(fd, buffer, BUFFER_SIZE);
	if(r == 0 && !stock)
		return(NULL);*/
	if(r == 0 && stock)
	{
		line = ft_strjoin(NULL,stock);
		free(stock);
		stock = NULL;
		return(line);
	}

	if(stock && r < BUFFER_SIZE)
	{
		line = ft_strjoin(NULL,stock);
		free(stock);
		stock = NULL;
		return(line);
	}

	line = get_line(stock);
	stock = clear(stock);
	return (line);
	/*stock = ft_strjoin(stock,buffer);*/
	//free(buffer);
	/*if(verif_line(stock) == 1)
	{ 
		line = get_line(stock);
		stock = clear(stock);
		return (line);
	}*/
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