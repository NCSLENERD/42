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

int best_pos(stck *head, int data)
{
	stck *curr;
	int	i;
	int	best_pos;
	int	val;

	best_pos = lstack(head);
	i = 0;
	val = 2147483647;
	curr = head;
	while(curr)
	{
		if (curr->data > data && curr->data < val)
		{
			val = curr->data;
			best_pos = i;
		}
		i++;
		curr = curr->next;
	}
	return(best_pos);
}

int	find_pos(stck *head, int data)	
{
	stck *curr;
	int	pos;

	pos = 0;
	curr = head;
	while(curr)
	{
		if (curr->data == data)
			return(pos);
		pos++;
		curr = curr->next;
	}
	return (pos);
}

int calc_cost(int pos ,int len)
{
	if(pos <= (len/2))
		return(pos);
	return (-(len - pos));
}

int total_cost(int ca, int cb)
{
	if (ca >= 0 && cb >= 0 )
		return (ft_max(ca, cb)); //rr
	else if (ca <= 0 && cb <= 0)
		return (ft_max(-ca, -cb));//rrr
	else
		return (ft_abs(ca) + ft_abs(cb));//sens opposé
}

int	best_move(stck *head_a , stck *head_b)
{
	int	cost;
	int	best_cost;
	int	res;
	stck*	curr;

	cost = 0;
	best_cost = 2147483647;
	curr = head_b;
	res = head_b->data;
	while(curr)
	{
		cost = total_cost(calc_cost(find_pos(head_b,curr->data),lstack(head_b)),calc_cost(best_pos(head_a,curr->data),lstack(head_a)));
		if (cost < best_cost)
		{
			best_cost = cost;
			res = curr->data;
		}
		curr = curr->next;
	}
	return (res);
}

void move_sort2(stck* head_a, stck* head_b, int cost_a ,int cost_b)
{
	if (cost_b < 0)
	{
	while (cost_b++ != 0)
		rrb(&head_b,0);
	}
	else  if(cost_b > 0)
	{
		while (cost_b-- != 0)
			rb(&head_b,0);
	}
	if (cost_a < 0)
	{
		while (cost_a++ != 0)
			rra(&head_a,0);
	}
	else  if(cost_a > 0)
	{
		while (cost_a-- != 0)
			ra(&head_a,0);
	}
}

void move_sort(stck* head_a, stck* head_b, int data)
{
	int cost_a;
	int cost_b;

	cost_a = calc_cost(best_pos(head_a,data),lstack(head_a));
	cost_b = calc_cost(find_pos(head_b,data),lstack(head_b));
	if (cost_b >= 0 && cost_a >= 0)
	{
		while(cost_b != 0 && cost_a != 0 )
		{
			rr(&head_a,&head_b);
			cost_b--;
			cost_a--;
		}
	}
	else if (cost_b <= 0 && cost_a <= 0)
	{
		while(cost_b != 0 && cost_a != 0 )
		{
			rrr(&head_a,&head_b);
			cost_b++;
			cost_a++;
		}
	}
	move_sort2(head_a, head_b, cost_a ,cost_b);
	pa(&head_a,&head_b);
}

int	find_min_pos(stck *head)
{
	int tmp;
	int pos;
	int i;

	tmp = head->data;
	i = 0;
	pos = 0;
	while(head)
	{
		if (head->data < tmp)
		{
			tmp = head->data;
			pos  = i;
		}
		head = head->next;
		i++;
	}
	return (pos);
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
	while((*head_b) != NULL)
	{
		bmove = best_move((*head_a),(*head_b));
		move_sort((*head_a), (*head_b), bmove);
	}
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

int	verif_err(int argc, char *argv[], stck **head)
{
	int	i;
	if(!isdigit_tab(argv))
	{
		write(2,"Error\n",6);
		exit(1);
	}
	i = 1;
	while(i < argc)
	{
		pushback(head,ft_atoi(argv[i]));
		i++;
	}
	if(!verifdoublon(*head))
	{
		write(2,"Error\n",6);
		exit(1);
	}
	return (1);
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

int main(int argc, char *argv[])
{ 
	stck *a;
	stck *b;

	a = NULL;
	b = NULL;
	if(verif_err(argc,argv,&a) &&  !is_sorted(a))
		push_swap(&a,&b,argc);
	printf("cost :%d\n",calc_cost(find_pos(a,2),lstack(a)));
	printf("Position : %d\n",find_pos(a,2));
	printf("Best Pos : %d\n",best_pos(a,2));
	printf("Min Pos : %d\n",find_min_pos(a));
	printlist(a);
	free_list(a);
	free_list(b);
	return (0);
}
 