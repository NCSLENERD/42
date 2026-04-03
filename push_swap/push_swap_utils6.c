/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 20:09:56 by nmayela           #+#    #+#             */
/*   Updated: 2026/04/03 20:09:57 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	movers2(t_stck **head_a, t_stck **head_b, int cost_a, int cost_b)
{
	if (cost_b < 0)
	{
		while (cost_b++ != 0)
			rrb(head_b, 0);
	}
	else if (cost_b > 0)
	{
		while (cost_b-- != 0)
			rb(head_b, 0);
	}
	if (cost_a < 0)
	{
		while (cost_a++ != 0)
			rra(head_a, 0);
	}
	else if (cost_a > 0)
	{
		while (cost_a-- != 0)
			ra(head_a, 0);
	}
}

void	movers(t_stck **head_a, t_stck **head_b, int *cost_a, int *cost_b)
{
	if (*cost_b >= 0 && *cost_a >= 0)
	{
		while (*cost_b != 0 && *cost_a != 0)
		{
			rr(head_a, head_b);
			(*cost_b)--;
			(*cost_a)--;
		}
	}
	else if (*cost_b <= 0 && *cost_a <= 0)
	{
		while (*cost_b != 0 && *cost_a != 0)
		{
			rrr(head_a, head_b);
			(*cost_a)++;
			(*cost_b)++;
		}
	}
}

void	move_sort(t_stck **head_a, t_stck **head_b, int data)
{
	int	cost_a;
	int	cost_b;

	if (is_max((*head_a), data))
	{
		push_max(head_a, head_b, data);
		pa(head_a, head_b);
		return ;
	}
	cost_a = calc_cost(best_pos((*head_a), data), lstack((*head_a)));
	cost_b = calc_cost(find_pos((*head_b), data), lstack((*head_b)));
	movers(head_a, head_b, &cost_a, &cost_b);
	movers2(head_a, head_b, cost_a, cost_b);
	pa(head_a, head_b);
}
