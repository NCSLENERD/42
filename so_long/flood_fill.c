/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:05:03 by nmayela           #+#    #+#             */
/*   Updated: 2026/04/27 15:05:05 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char *getln(char *str)
{
    char *res;
    int i;

    i = 0;
    res = malloc(sizeof(char) * ft_strlenV2(str) + 1);
    while (str[i])
    {
        res[i] = str[i];
        i++;
    }
	res[i] = '\0';
    return (res);
}

char **dupmap(t_game game)
{
    int i;
    char **dup;

    i = 0;

    dup = malloc(sizeof(char *) * game.map_height);
    while (i < game.map_height)
    {  
        dup[i] = getln(game.map[i]);
        i++;
    }
    return (dup);
}

void	fill(char **map, int x, int y, t_game game)
{
	/*int i;
	i = 0;
	while (i < game.map_height)
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("---------------------\n");*/
	if(map[y][x] != '1'  && map[y][x] != 'V')
	{
		map[y][x] = 'V';
		if(x < game.map_width - 1)
			fill(map, x + 1, y, game);
		if(y < game.map_height - 1)
			fill(map, x, y + 1, game);
		if(x > 0)
			fill(map, x - 1, y, game);
		if(y > 0) 
			fill(map, x, y - 1, game);
	}
	else
		return;
}

int	is_solvable(char **map, t_game game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < game.map_height)
	{
		while (map[i][j])
		{
			if(map[i][j] != 'V' && map[i][j] != '1' && map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	flood_fill(t_game game)
{
	char **map;
	int res;

	map = dupmap(game);
	fill(map, game.player_x, game.player_y, game);
	res = is_solvable(map, game);
	free_tab(map, game.map_height);
	return (res);
}