/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:11:02 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/06 19:44:48 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	stock_min;
	int	stock_max;
	int	i;
	int	x;

	i = 0;
	while (i < size)
	{
		stock_min = tab[i];
		x = i ;
		while (x < size)
		{
			if (stock_min > tab[x])
			{
				stock_max = stock_min;
				stock_min = tab[x];
				tab[x] = stock_max;
			}
			x++;
		}
		tab[i] = stock_min;
		i++;
	}
}
/*int main()
{
	int test[10] = {1,5,12,-3,49,-54,0,7,11,82};
	int i;
	
	ft_sort_int_tab(test,10);

	i = 0;
	while(i < 10)
	{
		printf("%d/ ",test[i]);
		i++; 
	}
}*/
