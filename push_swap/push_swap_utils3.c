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

void ra(stck** head,int flg)
{
	if((*head) == NULL || (*head)->next == NULL)
		return;
	pushback(head,(*head)->data);
	popfront(head);
	if(flg == 0)
			write(1,"ra\n",4);
}

void rb(stck** head,int flg)
{
	if((*head) == NULL || (*head)->next == NULL)
		return;
	pushback(head,(*head)->data);
	popfront(head);
	if(flg == 0)
			write(1,"rb\n",4);
}

void rr(stck** head_a , stck** head_b)
{
	ra(head_a,1);
	rb(head_b,1);
	write(1,"rr\n",4);
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

int	verifdoublon(stck *head)
{
	stck *curr1;
	stck *curr2;
	
	if(head == NULL)
		return(1);
	curr1 = head;
	while(curr1->next)
	{
		curr2 = curr1->next;
		while(curr2)
		{
			if(curr1->data == curr2->data)
				return (0);
			curr2 = curr2->next;
		}
		curr1 = curr1->next;
	}
	return (1);
}

