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

char	*get_linev(char *buffer)
{
	int		i;
	char	*stock;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	stock = malloc((sizeof(char) * i) + 2);
	if (!stock)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		stock[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		stock[i++] = '\n';
	stock[i] = '\0';
	return (stock);
}

char	*clear(char *str)
{
	char	*res;
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(str);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	i++;
	res = malloc(sizeof(char) * (len - i) + 1);
	if (!res)
		return (NULL);
	j = 0;
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}

char	*line_in_stock(char **stock, int r)
{
	char	*line;

	if (!*stock || **stock == '\0')
		return (NULL);
	if (r == 0 && *stock)
	{
		line = ft_strjoin(NULL, *stock);
		free(*stock);
		*stock = NULL;
		return (line);
	}
	line = get_linev(*stock);

	*stock = clear(*stock);
	return (line);
}

char	*concat_stock_and_buffer(char *stock, char *buffer, int r)
{
	char	*tmp;

	buffer[r] = '\0';
	tmp = ft_strjoin(stock, buffer);
	free(stock);
	free(buffer);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stock;
	int			r;

	while (1)
	{
		buffer = malloc (sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == 0)
		{
			free (buffer);
			break ;
		}
		if (r == -1)
		{
			free (buffer);
			return (NULL);
		}
		stock = concat_stock_and_buffer(stock, buffer, r);
		if (verif_line(stock) == 1)
			break ;
	}
	return (line_in_stock(&stock, r));
}
/*int main()
{
    char* name = "test.txt";
    int fd = open(name, O_RDWR);
    
    char *line;

    line = get_next_line(fd);  // récupère la première ligne
    if (line)
    {
        printf("%s", line);    // affiche
        free(line);            // libère la mémoire
    }
	close(fd);
	return 0;
}*/
