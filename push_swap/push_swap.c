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

int	verifdoublon(stck *head)
{
	stck *curr1;
	stck *curr2;
	
	if(head == NULL)
		return(1);
	curr1 = head;
	while(curr1->next)
	{
		curr2 = curr1->next;
		while(curr2)
		{
			if(curr1->data == curr2->data)
				return (0);
			curr2 = curr2->next;
		}
		curr1 = curr1->next;
	}
	return (1);
}

int	isdigit_tab(char **tab)
{
	int i;
	int j;

	i = 1;
	while (tab[i])
	{
		j = 0;
		if (tab[i][0] == '-' || tab[i][0] == '+')
			j = 1;
		while (tab[i][j])
		{
			if (tab[i][j] < '0' || tab[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int main(int argc, char *argv[])
{ 
	int i;
	stck *a;
	stck *b;

	if(!isdigit_tab(argv))
	{
		write(2,"Error\n",6);
		exit(1);
	}
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
