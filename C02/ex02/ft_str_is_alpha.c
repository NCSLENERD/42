/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:26:16 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/07 19:56:49 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!('A' <= str[i] && str[i] <= 'Z'))
		{
			if (!('a' <= str[i] && str[i] <= 'z'))
				return (0);
		}
		else if (!('a' <= str[i] || str[i] <= 'z'))
		{
			if (!('A' <= str[i] && str[i] <= 'Z'))
				return (0);
		}
		i++;
	}
	return (1);
}
/*int main(void)
{
	char *test = "test";
	char *test1 = "lolLLLKKKsKja";
	char *test2 = "aa!ddd!dd";

	printf("%d",ft_str_is_alpha(test));
	printf("%d",ft_str_is_alpha(test1));
	printf("%d",ft_str_is_alpha(test2));

	return 0;	
}*/
