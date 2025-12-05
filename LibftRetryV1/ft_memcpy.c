/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:57:06 by nmayela           #+#    #+#             */
/*   Updated: 2025/11/25 19:57:09 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*result;
	unsigned char	*src_stock;

	if (!dest && !src)
		return (NULL);
	i = 0;
	result = (unsigned char *)dest;
	src_stock = (unsigned char *)src;
	while (i < n)
	{
		result[i] = src_stock[i];
		i++;
	}
	return (dest);
}
/*int main() {

    int array [] = { 54, 85, 20, 63, 21 };
    int * copy = NULL;
    int length = sizeof( int ) * 5;
       
    //Memory allocation and copy 
    copy = (int *) malloc( length );
    ft_memcpy( copy, array, length );
        
    //Display the copied values
    for( length=0; length<5; length++ ) {
        printf( "%d ", copy[ length ] );
    }
    printf( "\n" );
    
    return 0;
}*/