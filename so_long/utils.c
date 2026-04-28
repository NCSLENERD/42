/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:50:19 by nmayela           #+#    #+#             */
/*   Updated: 2026/04/27 18:50:20 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

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
	{
		free_tab(game->map, game->map_height);
		game->map = NULL;
	}
	if(game->img_collect)
		mlx_destroy_image(game->mlx, game->img_collect);
	if(game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if(game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if(game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if(game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if(game->win)
		mlx_destroy_window(game->mlx, game->win);
	if(game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	error_exit(t_game *game , char *msg)
{
	write(2,"Error\n",6);
	write(2,msg,ft_strlenV2(msg));
	write(2,"\n",1);
	free_game(game);
	exit(1);

}

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
