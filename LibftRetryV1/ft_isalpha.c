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

int	ft_isalpha(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	return (0);
}
/*int main(void)
{
    //ft_isalpha
    printf("La fonction isalpha\n");
    printf("La lettre z : %d\n",ft_isalpha('z'));
    printf("La lettre a : %d\n",ft_isalpha('a'));
    printf("La lettre A : %d\n",ft_isalpha('A'));
    printf("La lettre Z : %d\n",ft_isalpha('Z'));
    printf("La lettre o : %d\n",ft_isalpha('o'));
    printf("Le chiffre 5 : %d\n",ft_isalpha('5'));
    printf("\n");

}*/