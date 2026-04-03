/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 19:21:09 by nmayela           #+#    #+#             */
/*   Updated: 2026/04/02 19:21:10 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int calc_cost(int pos ,int len)
{
	if(pos <= (len/2))
		return(pos);
	return (-(len - pos));
}

int total_cost(int ca, int cb)
{
	if (ca >= 0 && cb >= 0 )
		return (ft_max(ca, cb));
	else if (ca <= 0 && cb <= 0)
		return (ft_max(-ca, -cb));
	else
		return (ft_abs(ca) + ft_abs(cb));
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

void move_sort2(stck  **head_a, stck **head_b, int cost_a ,int cost_b)
{
	if (cost_b < 0)
	{
	while (cost_b++ != 0)
		rrb(head_b,0);
	}
	else  if(cost_b > 0)
	{
		while (cost_b-- != 0)
			rb(head_b,0);
	}
	if (cost_a < 0)
	{
		while (cost_a++ != 0)
			rra(head_a,0);
	}
	else  if(cost_a > 0)
	{
		while (cost_a-- != 0)
			ra(head_a,0);
	}
}

void move_sort(stck **head_a, stck **head_b, int data)
{
	int cost_a;
	int cost_b;

	if(is_max((*head_a), data))
	{
		push_max(head_a, head_b, data);
		pa(head_a, head_b);
		return;
	}
	cost_a = calc_cost(best_pos((*head_a),data),lstack((*head_a)));
	cost_b = calc_cost(find_pos((*head_b),data),lstack((*head_b)));
	if (cost_b >= 0 && cost_a >= 0)
	{
		while(cost_b != 0 && cost_a != 0 )
		{
			rr(head_a,head_b);// probleme ici on fait bien un rr mais on met le dernier devant ??
			cost_b--;	
			cost_a--;
		}
	}
	else if (cost_b <= 0 && cost_a <= 0)
	{
		while(cost_b != 0 && cost_a != 0 )
		{
			rrr(head_a,head_b);
			cost_b++;
			cost_a++;
		}
	}
	move_sort2(head_a, head_b, cost_a ,cost_b);
	pa(head_a,head_b);
}