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
		{
			printf("borne col fausse\n");
			return(0);
		}
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

int	verif_c(char **str, int map_height)
{
	int	x;
	int	y;
	int count;

	x = 0;
	y = 0;
	count = 0;
	while(x < map_height )
	{
		while(str[x][y])
		{
			if(str[x][y] == 'C')
				count++;
			y++;
		}
		x++;
		y = 0;
	}
	return (count);
}

int	verif_e(char **str, int map_height)
{
	int	x;
	int	y;
	int count;

	x = 0;
	y = 0;
	count = 0;
	while(x < map_height )
	{
		while(str[x][y])
		{
			if(str[x][y] == 'E')
				count++;
			y++;
		}
		x++;
		y = 0;
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
	while(x < game->map_height )
	{
		while(str[x][y])
		{
			if(str[x][y] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				count++;
			}
			y++;
		}
		x++;
		y = 0;
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
	c = verif_c(game->map, game->map_height);
	p = verif_p(game->map, game);
	e = verif_e(game->map, game->map_height);
	if( c >= 1 && p == 1 && e == 1)
	{
		game->collect_remain = c;
		return (1);
	}
	return (0);
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
	init_map(&game,"test.ber");
	i = 0;
	while (i < game.map_height)
	{
		printf("%s\n", game.map[i]);
		i++;
	}
	printf("verif width:%d\n",verif_width(&game));
	printf("width: %d\n",game.map_width);
	printf("height: %d\n",game.map_height);
	printf("borne : %d\n",verif_borne(game));
	printf("content : %d\n",verif_content(&game));
	printf("files verif : %d \n",verif_files("....ber"));
	printf("player pos x : %d\n",game.player_x);
	printf("player pos y : %d\n",game.player_y);

	return (0);
}