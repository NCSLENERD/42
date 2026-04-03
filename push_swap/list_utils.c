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

t_stck	*create_node(int nb)
{
	t_stck	*newnode;

	newnode = malloc(sizeof(t_stck));
	if (newnode == NULL)
		return (NULL);
	newnode->data = nb;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

void	free_list(t_stck *head)
{
	t_stck	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	printlist(t_stck *head)
{
	t_stck	*curr;

	curr = head;
	while (curr)
	{
		ft_putnbr_fd(curr->data, 1);
		write(1, ", ", 1);
		curr = curr->next;
	}
	write(1, "\n", 1);
}

void	pushfront(t_stck **head, int nb)
{
	t_stck	*newnode;

	newnode = create_node(nb);
	newnode->next = *head;
	newnode->prev = NULL;
	if (*head != NULL)
		(*head)->prev = newnode;
	*head = newnode;
}

void	pushback(t_stck **head, int nb)
{
	t_stck	*newnode;
	t_stck	*curr;

	if (*head == NULL)
	{
		*head = create_node(nb);
		return ;
	}
	newnode = create_node(nb);
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = newnode;
	newnode->prev = curr;
}
