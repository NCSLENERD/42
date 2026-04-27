/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:05:03 by nmayela           #+#    #+#             */
/*   Updated: 2026/04/27 15:05:05 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "minilibx-linux/mlx.h"
#include <stdio.h>

char **dupmap(t_game game)
{
    int i;
    int j;
    int x;
    int y;
    char **dup;

    i = 0;
    j = 0;
    y = 0;
    x = 0;
    dup = malloc(sizeof(char *) * game.map_height);
    while (game.map[i])
    {  
        dup[i] = getln(game.map[i]);
        i++;
    }
    return (dup);
}

char *getln(char *str)
{
    char *res;
    int i;

    i = 0;
    res = malloc(sizeof(char) * ft_strlenV2(str));
    while (str[i])
    {
        res[i] = str[i];
        i++;
    }
    return (res);
}

int main()
{
    char **test;

    test = dupmap()
    printf("")
}