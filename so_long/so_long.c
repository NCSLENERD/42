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

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "so_long");
	mlx_hook(win, 17, 0, close_win, mlx);
	mlx_loop(mlx);
	return (0);
}