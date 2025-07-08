/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 20:03:20 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/07 20:11:59 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(48 <= str[i] && str[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}
/*int main(void)
{
	char *test1 = "addffdsfsdfs10sdadas";
	char *test2 = "510dddsa256754";
	char *test3 = "123456789";
	char *test4 = "7*&^%$#$^";

	printf("%d",ft_str_is_numeric(test1));
	printf("%d",ft_str_is_numeric(test2));
	printf("%d",ft_str_is_numeric(test3));
	printf("%d",ft_str_is_numeric(test4));
}*/
