/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:36:31 by nmayela           #+#    #+#             */
/*   Updated: 2025/12/01 19:12:02 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <stdint.h>

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*result;
	size_t			i;

	i = 0;
	result = (unsigned char *)s;
	while (i < n)
	{
		result[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (size && nmemb > (SIZE_MAX / size))
		return (NULL);
	res = malloc((size) * nmemb);
	if (res == NULL)
		return (NULL);
	ft_bzero (res, nmemb * size);
	return (res);
}
/*int main(void)
{
	printf("%ld\n",SIZE_MAX);
	char *str;
	str = ft_calloc(10,ULONG_MAX);
	assert( str != NULL );
	printf("%p\n",str);
}*/