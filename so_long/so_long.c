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

int	close_win(void *param)
{
	mlx_loop_end(param);
	return (0);
}

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
	i = 0;
	while (i < game.map_height)
	{
		printf("%s\n", game.map[i]);
		i++;
	}
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, 800, 600, "so_long");
    mlx_hook(game.win, 17, 0, close_win, game.mlx);
	/* 4. (Phase 2 : load_textures + render_map ici) */

    /* 5. Lancer la boucle (BLOQUANT) */
    mlx_loop(game.mlx);
    free_game(&game);
    return (0);
  }