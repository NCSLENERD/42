/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:50:39 by nmayela           #+#    #+#             */
/*   Updated: 2026/04/27 18:50:40 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	verif_lcontent(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == 'P' || str[i] == '0'
				|| str[i] == '1' || str[i] == 'E' || str[i] == 'C'))
			return (0);
		i++;
	}
	return (1);
}

int	verif_ec(char **str, int map_height, char c)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (y < map_height)
	{
		while (str[y][x])
		{
			if (str[y][x] == c)
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
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (y < game->map_height)
	{
		while (str[y][x])
		{
			if (str[y][x] == 'P')
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

int	verif_content(t_game *game)
{
	int	i;
	int	p;
	int	e;
	int	c;

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
	if (c >= 1 && p == 1 && e == 1)
	{
		game->collect_remain = c;
		return (1);
	}
	return (0);
}

int	verif_map(t_game *game)
{
	if (!verif_width(game) || !verif_borne(*game)
		|| !verif_content(game) || !flood_fill(*game))
		return (0);
	return (1);
}
