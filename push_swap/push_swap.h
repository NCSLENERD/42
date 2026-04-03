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
# include <stdio.h>

typedef struct stck
{
	int			data;
	struct stck	*prev;
	struct stck	*next;
}	t_stck;

void	rt_err(void);
char	**ft_split(char const *s, char c);
void	push_max(t_stck **head_a, t_stck **head_b, int data);
int		is_max(t_stck *head, int data);
int		verif_err(int argc, char *argv[], t_stck **head, int flg);
void	move_sort(t_stck **head_a, t_stck **head_b, int data);
int		best_move(t_stck *head_a, t_stck *head_b);
int		total_cost(int ca, int cb);
int		calc_cost(int pos, int len);
int		find_min_pos(t_stck *head);
int		best_pos(t_stck *head, int data);
int		find_pos(t_stck *head, int data);
int		total_cost(int ca, int cb);
int		ft_abs(int n);
int		ft_max(int a, int b);
int		is_sorted(t_stck *head);
int		isdigit_tab(char **tab, int flg);
int		verifdoublon(t_stck *head);
int		lstack(t_stck *head);
int		ft_atoi(const char *nptr);
void	printlist(t_stck *head);
void	free_list(t_stck *head);
t_stck	*createNode(int nb);
void	ft_putnbr_fd(int n, int fd);
void	popback(t_stck **head);
void	popfront(t_stck **head);
void	pushback(t_stck **head, int nb);
void	pushfront(t_stck **head, int nb);
void	sa(t_stck **head, int flg);
void	sb(t_stck **head, int flg);
void	ss(t_stck **head_a, t_stck **head_b);
void	pa(t_stck **head_a, t_stck **head_b);
void	pb(t_stck **head_a, t_stck **head_b);
void	ra(t_stck **head, int flg);
void	rb(t_stck **head, int flg);
void	rr(t_stck **head_a, t_stck **head_b);
void	rra(t_stck **head, int flg);
void	rrb(t_stck **head, int flg);
void	rrr(t_stck **head_a, t_stck **head_b);

#endif