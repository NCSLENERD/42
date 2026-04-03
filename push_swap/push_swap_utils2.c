/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 19:35:41 by nmayela           #+#    #+#             */
/*   Updated: 2026/03/20 19:35:42 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rra(t_stck **head, int flg)
{
	t_stck	*curr;

	curr = *head;
	if ((*head) == NULL || (*head)->next == NULL)
		return ;
	while (curr->next)
		curr = curr->next;
	pushfront(head, curr->data);
	popback(head);
	if (flg == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stck **head, int flg)
{
	t_stck	*curr;

	curr = *head;
	if ((*head) == NULL || (*head)->next == NULL)
		return ;
	while (curr->next)
		curr = curr->next;
	pushfront(head, curr->data);
	popback(head);
	if (flg == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stck **head_a, t_stck **head_b)
{
	rra(head_a, 1);
	rrb(head_b, 1);
	write(1, "rrr\n", 4);
}

int	isdigit_tab(char **tab, int flg)
{
	int	i;
	int	j;

	i = 1;
	if (flg == 1)
		i = 0;
	while (tab[i])
	{
		if ((tab[i][0] == '-' || tab[i][0] == '+') && tab[i][1] == '\0')
			rt_err();
		j = 0;
		if (tab[i][0] == '-' || tab[i][0] == '+')
			j = 1;
		while (tab[i][j])
		{
			if (tab[i][j] < '0' || tab[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(t_stck *head)
{
	t_stck	*curr;

	if (head == NULL)
		return (1);
	curr = head;
	while (curr->next)
	{
		if (curr->data > curr->next->data)
			return (0);
		curr = curr->next;
	}
	return (1);
}
