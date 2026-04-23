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
#include <fcntl.h>
#include <stdio.h>
/*map doit faire plus de 2 colonnes , toutes les lignes ont la meme taille ,
verifier si map carré accepter , verifier si map a deux colonnes ql comportement ? a une colonne ? une ligne ? 2 lignes ? car ce sera remplit de mur*/
void	map_height(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error Cannot open file\n", 23);
		exit(1);
	}
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

void	parse_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	int			i;

	map_height(game,filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error Cannot open file\n", 23);
		exit(1);
	}
	line = get_next_line(fd);
	game->map = malloc(sizeof(char *) * game->map_height);
	if(!game->map)
		exit(1);
	i = 0;
	while (line != NULL)
	{
		game->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}
int main()
{
	t_game		game;
	int			i;

	game.mlx = NULL;
	game.win = NULL;
	game.map = NULL;
	game.map_width = 0;
	game.map_height = 0;
	game.player_x = 0;
	game.player_y = 0;
	game.collect_remain = 0;
	game.nbmoves = 0;
	parse_map(&game,"test.ber");
	i = 0;
	while (i < game.map_height)
	{
		printf("%s", game.map[i]);
		i++;
	}
	return (0);
}