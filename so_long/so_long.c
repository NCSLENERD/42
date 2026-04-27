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

int	main(int argc, char *argv[])
{
	void	*mlx;
	void	*win;
	t_game		game;
	int			i;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "so_long");
	mlx_hook(win, 17, 0, close_win, mlx);
	mlx_loop(mlx);

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
		error_exit(&game, "Too few or too many arguments");
	if (!verif_files(argv[1]))
		error_exit(&game, "Invalid file name or extension");
	init_map(&game,argv[1]);
	if(!verif_map(&game))
		error_exit(&game, "Invalid map");

	i = 0;
	while (i < game.map_height)
	{
		printf("%s\n", game.map[i]);
		i++;
	}
	free_game(&game)
}