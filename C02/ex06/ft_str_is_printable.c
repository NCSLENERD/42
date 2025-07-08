/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 20:36:15 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/07 20:50:21 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(32 <= str[i] && str[i] <= 126))
			return (0);
		if (str[i] == 127)
			return (0);
		i++;
	}
	return (1);
}
/*int main(void)
{
	char *test1 = "";
	char *test2 = "adasdfdsfsfsdfs#$%^&*(*^#$%^&**^%#";
	char *test3 = "dasdadaSASKASAHJDHDADADBADBAD";
	char *test4 = "yo";

	printf("%d",ft_str_is_printable(test1));
	printf("%d",ft_str_is_printable(test2));
	printf("%d",ft_str_is_printable(test3));
	printf("%d",ft_str_is_printable(test4));
}*/
