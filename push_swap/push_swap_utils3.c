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

void rra(stck** head,int flg)
{
	if((*head) == NULL || (*head)->next == NULL)
		return;
	pushback(head,(*head)->data);
	popfront(head);
	if(flg == 0)
			write(1,"rra\n",4);
}

void rrb(stck** head,int flg)
{
	if((*head) == NULL || (*head)->next == NULL)
		return;
	pushback(head,(*head)->data);
	popfront(head);
	if(flg == 0)
			write(1,"rrb\n",4);
}

void rrr(stck** head_a , stck** head_b)
{
	rra(head_a,1);
	rrb(head_b,1);
	write(1,"rrb\n",4);
}

int	lstack(stck *head)
{
	int	i;
	stck *curr;
	i = 0;
	curr = head;
	while(curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

