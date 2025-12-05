/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:34:01 by nmayela           #+#    #+#             */
/*   Updated: 2025/11/29 14:34:04 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

static	char	*add_string(const char *s, int len)
{
	int		i;
	char	*res;

	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = *s;
		i++;
		s++;
	}
	res[i] = '\0';
	return (res);
}

static char	**free_all(char **res, int last)
{
	while (last >= 0)
	{
		free(res[last]);
		last--;
	}
	free(res);
	return (NULL);
}

static int	simul_split(char const *s, char c)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i - j > 0)
			x++;
	}
	return (x);
}

static int	fill_split(char **res, char const *s, char c)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i - j > 0)
		{
			res[x] = add_string(&s[j], i - j);
			if (!res[x])
				return (free_all(res, x), 0);
			x++;
		}
	}
	res[x] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (simul_split(s, c) + 1));
	if (!res)
		return (NULL);
	if (!fill_split(res, s, c))
		return (NULL);
	return (res);
}
/*int main(void)
{
	char **test;
	int	i;

	i = 0;
	test = ft_split(NULL,'/');
	while (test[i])
	{
		printf("%s\n",test[i]);
		i++;
	}
}*/