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
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef  struct stck  {
	int data;
	struct stck *prev;
	struct stck *next;
} stck;

int total_cost(int ca, int cb);
int ft_abs(int n);
int	ft_max(int a, int b);
int	is_sorted(stck *head);
int	isdigit_tab(char **tab);
int	verifdoublon(stck *head);
int	lstack(stck *head);
int	ft_atoi(const char *nptr);
void printlist(stck *head);
void free_list(stck* head);
stck *createNode(int nb);
void	ft_putnbr_fd(int n, int fd);
void popback(stck **head);
void popfront(stck **head);
void pushback(stck **head, int nb);
void pushfront(stck **head, int nb);
void sa(stck** head,int flg);
void sb(stck** head,int flg);
void ss(stck** head_a, stck** head_b);
void pa(stck** head_a, stck **head_b);
void pb(stck** head_a, stck **head_b);
void ra(stck** head,int flg);
void rb(stck** head,int flg);
void rr(stck** head_a, stck** head_b);
void rra(stck** head,int flg);
void rrb(stck** head,int flg);
void rrr(stck** head_a , stck** head_b);

#endif