/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:55:23 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/06 19:48:17 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	var;

	var = *a;
	*a = var / *b;
	*b = var % *b;
}
/*int main (void)
{
	int nb1 = 52;
	int nb2 = 10;
	ft_ultimate_div_mod(&nb1,&nb2);

	printf("nb1 = %d nb2 = %d",nb1,nb2);

}*/
