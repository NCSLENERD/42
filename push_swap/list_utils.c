/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 18:12:14 by nmayela           #+#    #+#             */
/*   Updated: 2026/03/19 18:12:16 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

stck *createNode(int nb)
{
	stck *newnode = malloc(sizeof(stck));
	if(newnode == NULL)
		return (NULL);

	newnode->data = nb;
	newnode->next = NULL;
    newnode->prev = NULL;
	return newnode;
}

void free_list(stck* head) {
    stck* tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void printlist(stck *head)
{
	stck *curr = head;
	while(curr)
	{
		ft_putnbr_fd(curr->data,1);
		write(1,", ",1);
		curr = curr->next;
	}
	write(1,"\n",1);
}

void pushfront(stck **head, int nb)
{
    stck *newnode = createNode(nb);
    newnode->next = *head;
    newnode->prev = NULL;
    if (*head != NULL)
        (*head)->prev = newnode;

    *head = newnode;
}

void pushback(stck **head, int nb)
{
	if (*head == NULL)
	{
		*head = createNode(nb);
		return ;
	}
    stck *newnode = createNode(nb);
	stck *curr = *head;
	while(curr->next)
		curr = curr->next;
	curr->next = newnode;
	newnode->prev = curr;
}
