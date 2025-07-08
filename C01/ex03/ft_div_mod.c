/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:48:35 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/06 19:59:39 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*int main(void)
{
	int nb1;
	int nb2;

	ft_div_mod(42,10,&nb1,&nb2);

	printf("nb1 : %d  nb2 : %d",nb1,nb2);
}*/
