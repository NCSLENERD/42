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

int	ft_isalnum(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')
		|| ('0' <= c && c <= '9'))
		return (1);
	return (0);
}
/*int main(void)
{
    //ft_isalnum
    printf("La fonction isalnum\n");
    printf("Le chiffre 0: %d\n",ft_isalnum('0'));
    printf("Le chiffre 1: %d\n",ft_isalnum('1'));
    printf("Le chiffre 5: %d\n",ft_isalnum('5'));
    printf("Le chiffre 7: %d\n",ft_isalnum('7'));
    printf("Le chiffre 9: %d\n",ft_isalnum('9'));
    printf("La lettre E: %d\n",ft_isalnum('E'));
    printf("Avec le symbole (: %d\n",ft_isalnum('('));
    printf("\n");

}*/