/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:44:33 by nmayela           #+#    #+#             */
/*   Updated: 2025/07/10 19:07:03 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_capitalize(char *str)
{
	int	i;
	int	verif;

	i = 0;
	verif = 0;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (verif == 0 && str[i] >= 'a' && str[i] <= 'z' )
		{
			str[i] -= 32;
			verif = 1;
		}
		else if (verif == 0 && str[i] >= '0' && str[i] <= '9' )
		{
			verif = 1;
		}
		else if (!(str[i] >= 'a' && str[i] <= 'z')
			&& (!(str[i] >= '0' && str[i] <= '9')))
			verif = 0;
		i++;
	}
	return (str);
}
/*#include <stdio.h>
int	main(void)
{
	char	text1[] = "hi, how are you? 42words forty-two; fifty+and+one"; 
	
	ft_capitalize(text1);
	printf("%s", text1);
}*/
