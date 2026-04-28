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

#define TILE_SIZE 64
#include "get_nextline/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

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
	void	*img_wall;
	void	*img_floor;
	void	*img_collect;
	void	*img_player;
	void	*img_exit;
}	t_game;

void	map_height(t_game *game, char *filename);
int		verif_files(char *filename);
void	init_map(t_game *game, char *filename);
void	free_tab(char **map, int map_height);
void	free_game(t_game *game);
void	error_exit(t_game *game , char *msg);
int		ft_strlenV2(char *str);
int		verif_lcontent(char *str);
int		verif_ec(char **str, int map_height, char c);
int		verif_p(char **str, t_game *game);
int 	verif_content(t_game *game);
int		verif_map(t_game *game);
int		verif_width(t_game *game);
int		verif_lborne(char *str);
int		verif_borne(t_game game);
char	*getln(char *str);
char	**dupmap(t_game game);
void	fill(char **map, int x, int y, t_game game);
int		is_solvable(char **map, t_game game);
int		flood_fill(t_game game);


#endif

