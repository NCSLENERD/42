/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:50:29 by nmayela           #+#    #+#             */
/*   Updated: 2026/04/27 18:50:31 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	verif_width(t_game *game)
{
	int	width;
	int	i;

	width = ft_strlenv2(game->map[0]);
	i = 0;
	while (i < game->map_height)
	{
		if (width != ft_strlenv2(game->map[i]))
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
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	verif_borne(t_game game)
{
	int	i;

	i = 1;
	if (!verif_lborne(game.map[0])
		|| !verif_lborne(game.map[game.map_height - 1]))
		return (0);
	while (i < game.map_height - 1)
	{
		if (!(game.map[i][0] == '1')
			|| !(game.map[i][game.map_width - 1] == '1'))
			return (0);
		i++;
	}
	return (1);
}
