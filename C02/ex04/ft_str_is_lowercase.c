/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 20:13:18 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/07 20:25:49 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!('a' <= str[i] && str[i] <= 'z'))
			return (0);
		i++;
	}
	return (1);
}
/*int main(void)
{
	char *test1 = "abcedffdfdfsfdsfs";
	char *test2 = "dasdasdsaKdsadda";
	char *test3 = "asdadad#%^#%^&#adsa";
	char *test4 = "aaaa12123251";

	printf("%d",ft_str_is_lowercase(test1));
	printf("%d",ft_str_is_lowercase(test2));
	printf("%d",ft_str_is_lowercase(test3));
	printf("%d",ft_str_is_lowercase(test4));
}*/
