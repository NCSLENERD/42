/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayela <nmayela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:36:00 by nmayela           #+#    #+#             */
/*   Updated: 2026/03/13 17:36:01 by nmayela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef  struct stck  {
	int data;
	struct stck *prev;
	struct stck *next;
} stck;

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

void printlist(stck *head)
{
	stck *curr = head;
	while(curr)
	{
		printf("%d\n",curr->data);// mettre ft_printf
		curr = curr->next;
	}
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
    stck *newnode = createNode(nb);
	stck *curr = *head;
	while(curr->next)
		curr = curr->next;
	curr->next = newnode;
	newnode->prev = curr;
}

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
        *head = NULL;
  
	free(curr);
}

void insert_at(stck** head, int nb, unsigned int index)
{
	stck *curr;
	stck *newnode = createNode(nb);
	if(*head == NULL )
		return;
	curr = *head;

	while(curr && index > 0)
	{
		curr = curr->next;
		index--;
	}
	if(curr == NULL)
   		return;

	if(curr->prev == NULL)
    {
        pushfront(head, nb);
        return;
    }
	curr->prev->next = newnode;
	newnode->prev = curr->prev;
	newnode->next= curr;
	curr->prev = newnode;
}

void remove_at(stck** head, unsigned int index)
{
	stck *curr;
	if(*head == NULL)
		return;
	curr = *head;

	while(curr && index > 0)
	{
		curr = curr->next;
		index--;
	}
	if(curr == NULL)
   		return;
	if(curr->prev == NULL)
    {
        popfront(head);
        return;
    }
	if(curr->next == NULL)
	{
		popback(head);
		return;
	}
	curr->prev->next = curr->next;
	curr->next->prev= curr->prev;
	free(curr);
}

void sa(stck** head,int flg)
{
	int tmp;
	if(*head != NULL && (*head)->next != NULL)
	{
		tmp = (*head)->data;
		(*head)->data = (*head)->next->data;
		(*head)->next->data = tmp;
		if(flg == 0)
			write(1,"sa\n",3);
	}
}

void sb(stck** head,int flg)
{
	int tmp;
	if(*head != NULL && (*head)->next != NULL)
	{
		tmp = (*head)->data;
		(*head)->data = (*head)->next->data;
		(*head)->next->data = tmp;
		if(flg == 0)
			write(1,"sb\n",3);
	}
}

void ss(stck** head_a, stck** head_b)
{
	sa(head_a,1);
	sb(head_b,1);
	write(1,"ss\n",3);
}

int main()
{
	stck *mylist;
	stck *mylist2;

	mylist = createNode(1);
	pushback(&mylist, 2);
	pushback(&mylist,3);
	//popback(&mylist);
	mylist2 = createNode(4);
	pushback(&mylist2, 5);
	pushback(&mylist2,6);
	ss(&mylist,&mylist2);
	printlist(mylist);
	//sb(&mylist);
	printf("liste 2\n");
	printlist(mylist2);
	//printlist(mylist2);
}
