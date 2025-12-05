/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:01:26 by nmayela           #+#    #+#             */
/*   Updated: 2025/11/10 17:01:45 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <ctype.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*int main(void)
{
    //ft_isprint
    printf("La fonction isprint\n");
    printf("Le chiffre 0: %d\n",ft_isprint('0'));
    printf("Le chiffre 8: %d\n",ft_isprint('8'));
    printf("La lettre k: %d\n",ft_isprint('k'));
    printf("Le symbole espace ' ' : %d\n",ft_isprint(' '));
    printf("Avec /n : %d\n",ft_isprint('\n'));
    printf("\n");
}*/