/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:11:56 by nmayela           #+#    #+#             */
/*   Updated: 2026/04/23 15:11:57 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************* */
#include "so_long.h"

void	map_height(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(game, "Cannot open map file");
	line = get_next_line(fd);
	count = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	game->map_height = count;
	close(fd);
}

int	verif_files(char *filename)
{
	int	len;

	len = ft_strlenV2(filename);
	if(len <= 4)
		return(0);
	if(filename[len - 4] != '.')
		return(0);
	if(filename[len - 3] != 'b')
		return(0);
	if(filename[len - 2] != 'e')
		return(0);
	if(filename[len - 1] != 'r')
		return(0);
	return(1);
}

void	init_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	int			i;

	map_height(game,filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(game, "Cannot open map file");
	line = get_next_line(fd);
	game->map = malloc(sizeof(char *) * game->map_height);
	if(!game->map)
		error_exit(game, "Malloc failed");
	i = 0;
	while (line != NULL)
	{
		game->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}
