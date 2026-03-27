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
//trouver algo de tri

void	sort2(stck **head)
{
	if ((*head)->data > (*head)->next->data)
		sa(head, 0);
}

void sort3(stck **head)
{
	int	a;
	int	b;
	int	c;

	a = (*head)->data;
	b = (*head)->next->data;
	c = (*head)->next->next->data;

	if(a < b &&  c < b && a < c)// 1 3 2
	{
		rra(head,0);
		sa(head,0);
	}
	else if(a > b && c < a && c < b)// 3 2 1
	{
		ra(head,0);
		sa(head,0);
	}
	else if(a < b && b > c && c < a)// 2 3 1
		rra(head,0);
	else if(a > b && c > b && a < c)// 2 1 3
		sa(head,0);
	else if(a > b && a > c && b < c)//3 1 2
		ra(head,0);
}

int	verif_err(int argcv2, char *argvv2[], stck **head)
{
	int	i;
	if(!isdigit_tab(argvv2))
	{
		write(2,"Error\n",6);
		exit(1);
	}
	i = 1;
	while(i < argcv2)
	{
		pushback(head,ft_atoi(argvv2[i]));
		i++;
	}
	if(!verifdoublon(*head))
	{
		write(2,"Error\n",6);
		exit(1);
	}
	return (1);
}

void	push_swap(stck **a, stck **b, int argcv2)
{
	(void) b;
	if(argcv2 == 4)
		sort3(a);
	else if(argcv2 == 3)
		sort2(a);
}

int main(int argc, char *argv[])
{ 
	stck *a;
	stck *b;

	a = NULL;
	b= NULL;
	if(verif_err(argc,argv,&a) &&  !is_sorted(a))
		push_swap(&a,&b,argc);
	printlist(a);
	free_list(a);
	free_list(b);
	return (0);
}
