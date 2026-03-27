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

void rra(stck** head,int flg)
{
	stck *curr = *head;

	if((*head) == NULL || (*head)->next == NULL)
		return;
	while(curr->next)
		curr = curr->next;
	pushfront(head,curr->data);
	popback(head);
	if(flg == 0)
			write(1,"rra\n",4);
}

void rrb(stck** head,int flg)
{
	stck *curr = *head;

	if((*head) == NULL || (*head)->next == NULL)
		return;
	while(curr->next)
		curr = curr->next;
	pushfront(head,curr->data);
	popback(head);
	if(flg == 0)
			write(1,"rrb\n",4);
}

void rrr(stck** head_a, stck** head_b)
{
	ra(head_a,1);
	rb(head_b,1);
	write(1,"rrr\n",4);
}

int	isdigit_tab(char **tab)
{
	int i;
	int j;

	i = 1;
	while (tab[i])
	{
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

int	is_sorted(stck *head)
{
	stck *curr;
	
	if(head == NULL)
		return(1);
	curr = head;
	while(curr->next)
	{
		if(curr->data > curr->next->data)
			return(0);
		curr = curr->next;
	}
	
	return (1);
}