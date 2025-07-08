/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:12:04 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/08 14:47:10 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	stock;
	int	i;

	size--;
	i = 0;
	while (i <= size / 2)
	{
		stock = tab[i];
		tab[i] = tab[size - i];
		tab[size - i] = stock;
		i++;
	}
}
int	main(void) 
{
	int	test[1] = {1};
	ft_rev_int_tab(test,1);
	
	int 	i;
	i=0;
	while(i < 1)
	{
		printf("%d", test[i]);
		i++;
	}
}
