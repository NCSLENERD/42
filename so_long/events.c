/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:23:25 by nmayela           #+#    #+#             */
/*   Updated: 2026/04/28 18:23:27 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	close_win(void *param)
{
	free_game((t_game *)param);
	exit (0);
}

void try_move(t_game *game, int dx, int dy)
{
    int new_x;
    int new_y;
    char    c;

    new_x = game->player_x + dx;
    new_y = game->player_y + dy;
    c = game->map[new_y][new_x];
    if (c == '1')
        return;
    else if (c ==  'C')
    {
        game->collect_remain = game->collect_remain - 1;
        game->map[new_y][new_x] = '0';
    }
    else if (c == 'E' && game->collect_remain == 0)
    {
        game->nbmoves = game->nbmoves + 1;
        ft_printf("VICTOIRE en %d mooves.\n",game->nbmoves);
        close_win(game);
    }
    game->player_x = new_x;
    game->player_y = new_y;
    game->nbmoves = game->nbmoves + 1;
    ft_printf("nombre de mooves :%d\n",game->nbmoves);
    render_map(game);
}


int key_press(int keycode, t_game *game)
{
    if (keycode == 65307)
        close_win(game);
    else if (keycode == 119 || keycode == 65362)
        try_move(game, 0 , -1);
    else if (keycode == 115 || keycode == 65364)
        try_move(game, 0 , 1);
    else if (keycode == 97 || keycode == 65361)
        try_move(game, -1 , 0);
    else if (keycode == 100 || keycode == 65363)
        try_move(game, 1 , 0);
    return (0);
}