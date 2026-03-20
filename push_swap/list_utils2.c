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

void popfront(stck **head)
{
	if(*head == NULL)
		return;
	stck *curr = *head;
	*head = (*head)->next;
	if (*head != NULL) 
		(*head)->prev = NULL;
	free(curr);
}

void popback(stck **head)
{
	if(*head == NULL)
		return;
	stck *curr = *head;
	stck *tmp;
	while(curr->next)
		curr = curr->next;

	if (curr->prev != NULL)
	{
		tmp = curr->prev;
		tmp->next = NULL;
	}     
    else
	{                       
        *head = NULL;
	}
	free(curr);
}
