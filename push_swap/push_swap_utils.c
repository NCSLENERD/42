/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 19:33:26 by nmayela           #+#    #+#             */
/*   Updated: 2026/03/20 19:33:26 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stck **head, int flg)
{
	int	tmp;

	if (*head != NULL && (*head)->next != NULL)
	{
		tmp = (*head)->data;
		(*head)->data = (*head)->next->data;
		(*head)->next->data = tmp;
		if (flg == 0)
			write(1, "sa\n", 3);
	}
}

void	sb(t_stck **head, int flg)
{
	int	tmp;

	if (*head != NULL && (*head)->next != NULL)
	{
		tmp = (*head)->data;
		(*head)->data = (*head)->next->data;
		(*head)->next->data = tmp;
		if (flg == 0)
			write(1, "sb\n", 3);
	}
}

void	ss(t_stck **head_a, t_stck **head_b)
{
	sa(head_a, 1);
	sb(head_b, 1);
	write(1, "ss\n", 3);
}

void	pa(t_stck **head_a, t_stck **head_b)
{
	pushfront(head_a, (*head_b)->data);
	popfront(head_b);
	write(1, "pa\n", 3);
}

void	pb(t_stck **head_a, t_stck **head_b)
{
	pushfront(head_b, (*head_a)->data);
	popfront(head_a);
	write(1, "pb\n", 3);
}
