/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 23:07:53 by nmayela           #+#    #+#             */
/*   Updated: 2026/04/22 23:07:54 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "minilibx-linux/mlx.h"

void  init_game(t_game *game)
{
  game->mlx = NULL;
  game->win = NULL;
  game->map = NULL;
  game->map_width = 0;
  game->map_height = 0;
  game->player_x = 0;
  game->player_y = 0;
  game->collect_remain = 0;
  game->nbmoves = 0;
  game->img_wall = NULL;
  game->img_collect = NULL;
	game->img_player = NULL;
	game->img_floor = NULL;
	game->img_exit = NULL;
}

int  main(int argc, char *argv[])
{
	t_game  game;
	int	i;
	
	init_game(&game);
    if (argc != 2)
		error_exit(&game, "Too few or too many arguments");
    if (!verif_files(argv[1]))
		error_exit(&game, "Invalid file name or extension");
    init_map(&game, argv[1]);
	if (!verif_map(&game))
		error_exit(&game, "Invalid map");
  game.map[game.player_y][game.player_x] = '0';
	i = 0;
	while (i < game.map_height)
	{
		printf("%s\n", game.map[i]);
		i++;
	}
  game.mlx = mlx_init();
  game.win = mlx_new_window(game.mlx, game.map_width * TILE_SIZE, game.map_height * TILE_SIZE, "so_long");
  mlx_hook(game.win, 17, 0, close_win, &game);
  mlx_hook(game.win, 2, 1L << 0, key_press, &game);
  load_textures(&game);
  render_map(&game);
  mlx_loop(game.mlx);
  return (0);
}