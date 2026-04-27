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
/*faire flood fill /!\ */

int	ft_strlenV2(char *str)
{
	int	i;

	i = 0;
	if(!str)
		return(0);
	while(str[i])
		i++;
	return(i);
}

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

int	verif_width(t_game *game)
{
	int width;
	int	i;

	width = ft_strlenV2(game->map[0]);
	i = 0;
	while(i < game->map_height)
	{
		if (width != ft_strlenV2(game->map[i]))
			return (0);
		i++;
	}
	game->map_width = width;
	return (1);
}

int	verif_lborne(char *str)
{
	int	i;

	i = 0;
	if(!str)
		return(0);
	while(str[i])
	{
		if(str[i] != '1')
			return (0);
		i++;
	}
	return(1);
}
int	verif_borne(t_game game)
{
	int	i;

	i = 1;
	if(!verif_lborne(game.map[0]) || !verif_lborne(game.map[game.map_height - 1]))
		return (0);
	while(i < game.map_height - 1)
	{
		if(!(game.map[i][0] == '1') || !(game.map[i][game.map_width - 1] == '1'))
			return(0);
		i++;
	}
	return (1);
}

int	verif_lcontent(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if(!(str[i] == 'P' || str[i] == '0' || str[i] == '1' || str[i] == 'E' ||str[i] == 'C'))
			return(0);
		i++;
	}
	return(1);
}

int	verif_ec(char **str, int map_height, char c)
{
	int	x;
	int	y;
	int count;

	x = 0;
	y = 0;
	count = 0;
	while(y < map_height )
	{
		while(str[y][x])
		{
			if(str[y][x] == c)
				count++;
			x++;
		}
		y++;
		x = 0;
	}
	return (count);
}

int	verif_p(char **str, t_game *game)
{
	int	x;
	int	y;
	int count;

	x = 0;
	y = 0;
	count = 0;
	while(y < game->map_height )
	{
		while(str[y][x])
		{
			if(str[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				count++;
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (count);
}

int verif_content(t_game *game)
{
	int	i;
	int p;
	int e;
	int c;

	i = 0;
	p = 0;
	e = 0;
	c = 0;
	while (i < game->map_height)
	{
		if (!verif_lcontent(game->map[i]))
			return (0);
		i++;
	}
	c = verif_ec(game->map, game->map_height, 'C');
	p = verif_p(game->map, game);
	e = verif_ec(game->map, game->map_height, 'E');
	if( c >= 1 && p == 1 && e == 1)
	{
		game->collect_remain = c;
		return (1);
	}
	return (0);
}


//FLOOD FILL 

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

void	free_tab(char **map, int map_height)
{
	int	i;
	i = 0;

	while (i < map_height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_game(t_game *game)
{
	if(game->map)
		free_tab(game->map, game->map_height);
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

int	verif_map(t_game *game)
{
	if(!verif_width(game) || !verif_borne(*game) || !verif_content(game) || !flood_fill(*game))
		return (0);
	return (1);
}

int main(int argc , char * argv[])
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

	if(argc != 2)
		return (0);
	if (!verif_files(argv[1]))
	{
		return (0);
	}
	init_map(&game,argv[1]);
	printf("verif_map: %d\n",verif_map(&game));

	i = 0;
	while (i < game.map_height)
	{
		printf("%s\n", game.map[i]);
		i++;
	}
	return (0);
}