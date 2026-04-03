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

int	calc_cost(int pos, int len)
{
	if (pos <= (len / 2))
		return (pos);
	return (-(len - pos));
}

int	total_cost(int ca, int cb)
{
	if (ca >= 0 && cb >= 0)
		return (ft_max(ca, cb));
	else if (ca <= 0 && cb <= 0)
		return (ft_max(-ca, -cb));
	else
		return (ft_abs(ca) + ft_abs(cb));
}

int	best_move(t_stck *head_a, t_stck *head_b)
{
	int		cost;
	int		best_cost;
	int		res;
	t_stck	*curr;

	cost = 0;
	best_cost = 2147483647;
	curr = head_b;
	res = head_b->data;
	while (curr)
	{
		cost = total_cost(
				calc_cost(find_pos(head_b, curr->data), lstack(head_b)),
				calc_cost(best_pos(head_a, curr->data), lstack(head_a))
				);
		if (cost < best_cost)
		{
			best_cost = cost;
			res = curr->data;
		}
		curr = curr->next;
	}
	return (res);
}
