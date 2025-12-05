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

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}
/*int main(void)
{
    //ft_isascii
    printf("La fonction isascii\n");
    printf("Le chiffre 0: %d\n",ft_isascii('0'));
    printf("La lettre  J: %d\n",ft_isascii('J'));
    printf("Le caractere représenter par 200: %d\n",ft_isascii(200));
    printf("test avec vrai isascii : %d\n",isascii(200));
    printf("\n");
}*/