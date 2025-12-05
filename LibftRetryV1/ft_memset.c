/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:57:02 by nmayela           #+#    #+#             */
/*   Updated: 2025/11/24 22:57:06 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*result;

	result = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		result[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
/*int main() {

    char array [] = { 'a', 'y', 'z', 'w', 'b' ,'b'};
    size_t size = sizeof( char ) * 6;
    char text[10] = "XXXXXXX";
    int length;
    
    for( length=0; length<6; length++) {
        printf( "%c ", array[ length ] );
    }
    printf( "\n" );

    ft_memset( array, 't', size );

    for( length=0; length<6; length++) {
        printf( "%c ", array[ length ] );
    }
    printf( "\n" );
    ft_memset( text, 'A' , 10);
    printf("%s",text);
    
    return 0;
}*/