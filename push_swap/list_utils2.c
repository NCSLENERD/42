/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 19:14:22 by nmayela           #+#    #+#             */
/*   Updated: 2026/03/20 19:14:23 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	popfront(t_stck **head)
{
	t_stck	*curr;

	if (*head == NULL)
		return ;
	curr = *head;
	*head = (*head)->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(curr);
}

void	popback(t_stck **head)
{
	t_stck	*curr;
	t_stck	*tmp;

	if (*head == NULL)
		return ;
	curr = *head;
	while (curr->next)
		curr = curr->next;
	if (curr->prev != NULL)
	{
		tmp = curr->prev;
		tmp->next = NULL;
	}
	else
		*head = NULL;
	free(curr);
}

int	verif_err(int argc, char *argv[], t_stck **head, int flg)
{
	int	i;

	if (!isdigit_tab(argv, flg))
		rt_err();
	i = 0;
	if (flg == 0)
		i = 1;
	while (i < argc)
	{
		pushback(head, ft_atoi(argv[i]));
		i++;
	}
	if (!verifdoublon(*head))
		rt_err();
	return (1);
}

int	is_max(t_stck *head, int data)
{
	while (head)
	{
		if (head->data > data)
			return (0);
		head = head->next;
	}
	return (1);
}

void	push_max(t_stck **head_a, t_stck **head_b, int data)
{
	int	cost_a;
	int	cost_b;

	cost_a = calc_cost(find_min_pos((*head_a)), lstack((*head_a)));
	if (cost_a > 0)
	{
		while (cost_a-- != 0)
			ra(head_a, 0);
	}
	else
	{
		while (cost_a++ != 0)
			rra(head_a, 0);
	}
	cost_b = calc_cost(find_pos((*head_b), data), lstack((*head_b)));
	if (cost_b > 0)
	{
		while (cost_b-- != 0)
			rb(head_b, 0);
	}
	else
	{
		while (cost_b++ != 0)
			rrb(head_b, 0);
	}
}
