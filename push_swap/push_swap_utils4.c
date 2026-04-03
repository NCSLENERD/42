/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:20:28 by nmayela           #+#    #+#             */
/*   Updated: 2026/04/02 15:20:29 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int ft_abs(int n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

int	find_min_pos(stck *head)
{
	int tmp;
	int pos;
	int i;

	tmp = head->data;
	i = 0;
	pos = 0;
	while(head)
	{
		if (head->data < tmp)
		{
			tmp = head->data;
			pos  = i;
		}
		head = head->next;
		i++;
	}
	return (pos);
}

int best_pos(stck *head, int data)
{
	stck *curr;
	int	i;
	int	best_pos;
	int	val;

	best_pos = lstack(head);
	i = 0;
	val = 2147483647;
	curr = head;
	while(curr)
	{
		if (curr->data > data && curr->data < val)
		{
			val = curr->data;
			best_pos = i;
		}
		i++;
		curr = curr->next;
	}
	return(best_pos);
}
int	find_pos(stck *head, int data)	
{
	stck *curr;
	int	pos;

	pos = 0;
	curr = head;
	while(curr)
	{
		if (curr->data == data)
			return(pos);
		pos++;
		curr = curr->next;
	}
	return (pos);
}