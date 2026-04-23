/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 00:50:23 by nmayela           #+#    #+#             */
/*   Updated: 2026/04/23 00:50:24 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
#define SO_LONG_H

#include "get_nextline/get_next_line.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collect_remain;
	int		nbmoves;
}	t_game;

void	parse_map(t_game *game, char *filename);

#endif

