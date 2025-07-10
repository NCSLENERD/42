/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:24:08 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/10 16:53:40 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			if (ft_strcmp(&str[i], &to_find[0]))
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
/*#include <string.h>
#include <stdio.h>
int main(void)
{
	char text[] = " jo=ubonjfdfdfdfddd43434779rfddjo";
	char textatrouver[] = "jou";

	printf("%s",ft_strstr(text,textatrouver));
	printf("\n");
	printf("%s",strstr(text,textatrouver));
}*/
