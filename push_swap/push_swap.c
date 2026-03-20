/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*   Created: 2026/03/13 17:36:00 by nmayela           #+#    #+#             */
/*   Updated: 2026/03/13 17:36:01 by nmayela          ###   ########.fr       */
/*                                                                            */
/*                                                +#+#+#+#+#+   +#+           */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>
//faire verif push_swap , si doublon / pas int / trop grand int 
//trouver algo de tri
int main(int argc, char *argv[])
{
	int i;
	stck *a;
	stck *b;

	a = NULL;
	b= NULL;
	i = 1;
	while(i < argc)
	{
		pushback(&a,ft_atoi(argv[i]));
		i++;
	}
	printlist(a);

}
