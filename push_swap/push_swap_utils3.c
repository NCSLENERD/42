/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 19:36:43 by nmayela           #+#    #+#             */
/*   Updated: 2026/03/20 19:36:53 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ra(t_stck **head, int flg)
{
	if ((*head) == NULL || (*head)->next == NULL)
		return ;
	pushback(head, (*head)->data);
	popfront(head);
	if (flg == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stck **head, int flg)
{
	if ((*head) == NULL || (*head)->next == NULL)
		return ;
	pushback(head, (*head)->data);
	popfront(head);
	if (flg == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stck **head_a, t_stck **head_b)
{
	ra(head_a, 1);
	rb(head_b, 1);
	write(1, "rr\n", 3);
}

int	lstack(t_stck *head)
{
	int		i;
	t_stck	*curr;

	i = 0;
	curr = head;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

int	verifdoublon(t_stck *head)
{
	t_stck	*curr1;
	t_stck	*curr2;

	if (head == NULL)
		return (1);
	curr1 = head;
	while (curr1->next)
	{
		curr2 = curr1->next;
		while (curr2)
		{
			if (curr1->data == curr2->data)
				return (0);
			curr2 = curr2->next;
		}
		curr1 = curr1->next;
	}
	return (1);
}
