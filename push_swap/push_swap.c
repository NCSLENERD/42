/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:18:42 by nmayela           #+#    #+#             */
/*   Updated: 2026/04/03 19:18:44 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

void	sort2(t_stck **head)
{
	if ((*head)->data > (*head)->next->data)
		sa(head, 0);
}

void	sort3(t_stck **head)
{
	int	a;
	int	b;
	int	c;

	a = (*head)->data;
	b = (*head)->next->data;
	c = (*head)->next->next->data;
	if (a < b && c < b && a < c)
	{
		rra(head, 0);
		sa(head, 0);
	}
	else if (a > b && c < a && c < b)
	{
		ra(head, 0);
		sa(head, 0);
	}
	else if (a < b && b > c && c < a)
		rra(head, 0);
	else if (a > b && c > b && a < c)
		sa(head, 0);
	else if (a > b && a > c && b < c)
		ra(head, 0);
}

void	turk(t_stck **head_a, t_stck **head_b)
{
	int	cost;
	int	bmove;

	cost = 0;
	bmove = 0;
	while (lstack((*head_a)) > 3)
		pb(head_a, head_b);
	sort3(head_a);
	while ((*head_b) != NULL)
	{
		bmove = best_move((*head_a), (*head_b));
		move_sort(head_a, head_b, bmove);
	}
	cost = calc_cost(find_min_pos((*head_a)), lstack((*head_a)));
	if (cost < 0)
	{
		while (cost++ != 0)
			rra(head_a, 0);
	}
	else
	{
		while (cost-- != 0)
			ra(head_a, 0);
	}
}

void	push_swap(t_stck **a, t_stck **b)
{
	int	size;

	size = lstack(*a);
	if (size == 3)
		sort3(a);
	else if (size == 2)
		sort2(a);
	else
		turk(a, b);
}

int	main(int argc, char *argv[])
{
	t_stck	*a;
	t_stck	*b;
	int		i;
	int		flg;

	i = 0;
	flg = 0;
	a = NULL;
	b = NULL;
	if (argc == 2 && argv[1][0] == '\0')
		rt_err();
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		while (argv[i])
			i++;
		argc = i;
		flg = 1;
	}
	if (verif_err(argc, argv, &a, flg) && !is_sorted(a))
		push_swap(&a, &b);
	free_list(a);
	free_list(b);
	return (0);
}
