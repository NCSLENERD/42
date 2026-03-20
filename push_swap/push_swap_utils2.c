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

void ra(stck** head,int flg)
{
	stck *curr = *head;

	if((*head) == NULL || (*head)->next == NULL)
		return;
	while(curr->next)
		curr = curr->next;
	pushfront(head,curr->data);
	popback(head);
	if(flg == 0)
			write(1,"ra\n",3);
}

void rb(stck** head,int flg)
{
	stck *curr = *head;

	if((*head) == NULL || (*head)->next == NULL)
		return;
	while(curr->next)
		curr = curr->next;
	pushfront(head,curr->data);
	popback(head);
	if(flg == 0)
			write(1,"rb\n",3);
}

void rr(stck** head_a, stck** head_b)
{
	ra(head_a,1);
	rb(head_b,1);
	write(1,"rr\n",3);
}
