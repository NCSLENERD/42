/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 18:13:03 by nmayela           #+#    #+#             */
/*   Updated: 2026/03/19 18:13:04 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef  struct stck  {
	int data;
	struct stck *prev;
	struct stck *next;
} stck;


void free_list(stck* head);
stck *createNode(int nb);
void remove_at(stck** head, unsigned int index);//pas sur
void insert_at(stck** head, int nb, unsigned int index);//pas sur
void popback(stck **head);
void popfront(stck **head);
void pushback(stck **head, int nb);
void pushfront(stck **head, int nb);
#endif