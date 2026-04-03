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
	if(a < b &&  c < b && a < c)
	{
		rra(head,0);
		sa(head,0);
	}
	else if(a > b && c < a && c < b)
	{
		ra(head,0);
		sa(head,0);
	}
	else if(a < b && b > c && c < a)
		rra(head,0);
	else if(a > b && c > b && a < c)
		sa(head,0);
	else if(a > b && a > c && b < c)
		ra(head,0);
}

void	turk(stck **head_a, stck **head_b)
{
	int cost;
	int	bmove;

	cost = 0;
	bmove = 0;
	while(lstack((*head_a)) > 3)
		pb(head_a,head_b);
	sort3(head_a);
	printlist((*head_a));
	printf("/o/\n");
	printlist((*head_b));
	while((*head_b) != NULL)
	{
		bmove = best_move((*head_a),(*head_b));
		move_sort(head_a, head_b, bmove);
		printlist((*head_a));
		printf("/o/\n");
		printlist((*head_b));
	}
		printlist((*head_a));
	cost = calc_cost(find_min_pos((*head_a)),lstack((*head_a)));
	if(cost < 0)
	{
		while(cost++ != 0)
			rra(head_a,0);
	}
	else
	{
		while(cost-- != 0)
			ra(head_a,0);
	}
}

void	push_swap(stck **a, stck **b, int argc)
{
	if(argc == 4)
		sort3(a);
	else if(argc == 3)
		sort2(a);
	else
		turk(a,b);
}

//gerer les string, donc faire un ft_split si argc == 2
int main(int argc, char *argv[])
{ 
	stck *a;
	stck *b;
	int	i;
	int flg;

	i = 0;
	flg = 0;
	a = NULL;
	b = NULL;
	if(argc == 2)
	{
		argv = ft_split(argv[1],' ');
		while(argv[i])
		{
		printf("i :%d  nb:%s\n",i,argv[i]);
			i++;
		}
		argc = i;
		flg = 1;
	}
	if(verif_err(argc,argv,&a,flg) &&  !is_sorted(a))
		push_swap(&a,&b,argc);
	printf("Trier? : %d",is_sorted(a));
	printlist(a);
	free_list(a);
	free_list(b);
	return (0);
}
 