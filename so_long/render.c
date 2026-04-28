/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:46:11 by nmayela           #+#    #+#             */
/*   Updated: 2026/04/28 15:46:12 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "minilibx-linux/mlx.h"

void    load_textures(t_game *game)
{
    void    *img;
    int     h;
    int     w;


    img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &w, &h);
    if (!img)
        error_exit(game, "Failed to load floor texture");
    game->img_floor = img;
    img = mlx_xpm_file_to_image(game->mlx, "textures/collect.xpm", &w, &h);
    if (!img)
        error_exit(game, "Failed to load collect texture");
    game->img_collect = img;
    img = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &w, &h);
    if (!img)
        error_exit(game, "Failed to load player texture");
    game->img_player = img;
    img = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &w, &h);
    if (!img)
        error_exit(game, "Failed to load exit texture");
    game->img_exit = img;
    img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w, &h);
    if (!img)
        error_exit(game, "Failed to load wall texture");
    game->img_wall = img;
}

void    render_tile(t_game *game, int x, int y)
{   
    char c;

    c = game->map[y][x];
    mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * TILE_SIZE, y *TILE_SIZE);
    if(c == '1')
        mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * TILE_SIZE, y *TILE_SIZE);
    else if(c == 'P')
        mlx_put_image_to_window(game->mlx, game->win, game->img_player, x * TILE_SIZE, y *TILE_SIZE);
    else if(c == 'C')
        mlx_put_image_to_window(game->mlx, game->win, game->img_collect, x * TILE_SIZE, y *TILE_SIZE);
    else if(c == 'E')
        mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * TILE_SIZE, y *TILE_SIZE);
}

void    render_map(t_game *game)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < game->map_height)
    {
        while (x < game->map_width)
        {
            render_tile(game, x, y);
            x++;
        }
        y++;
        x = 0;
    }
}