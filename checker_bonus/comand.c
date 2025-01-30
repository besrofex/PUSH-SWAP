/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:04:41 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/30 13:08:17 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void swap(t_stack **head)
{
    t_stack *first;
    t_stack *second;

    if (head == NULL || *head == NULL || (*head)->next == NULL)
        return;
    first = *head;
    second = first->next;
    first->next = second->next;
    if (second->next != NULL)
        second->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    *head = second;
}

void    sa(t_stack **a, bool checker)
{
   swap(a);
	if (!checker)
		write(1,"sa\n",3);
}

void    sb(t_stack **b, bool checker)
{
   swap(b);
	if (!checker)
		write(1,"sb\n",3);
}

void    ss(t_stack **b, t_stack **a, bool checker)
{
	swap(a);
   swap(b);
	if (!checker)
		write(1,"ss\n",3);
}

static void	rotate(t_stack **head)
{
	t_stack *last_node;
	
	if (head == NULL || *head == NULL || (*head)->next == NULL)
        return ;
	last_node = ft_lstlast(*head);
	*head = (*head)->next;
	last_node->next = (*head)->prev;
	(*head)->prev->prev = last_node;
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;
}

void	ra(t_stack **a, bool checker)
{
	rotate(a);
	if (!checker)
		write(1,"ra\n",3);
}

void	rb(t_stack **b, bool checker)
{
	rotate(b);
	if (!checker)
		write(1,"rb\n",3);
}

void	rr(t_stack **a, t_stack **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		write(1,"rra\n",4);
}

static void	reverse_rotate(t_stack	**head)
{
	t_stack	*last_node;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
      return ;
	last_node = ft_lstlast(*head);
	last_node->next = *head;
	(*head)->prev = last_node;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	*head = last_node;
}

void	rra(t_stack **a, bool checker)
{
	reverse_rotate(a);
	if (!checker)
		write(1,"rra\n",4);
}

void	rrb(t_stack **b, bool checker)
{
	reverse_rotate(b);
	if (!checker)
		write(1,"rrb\n",4);
}

void	rrr(t_stack **a, t_stack **b, bool checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		write(1,"rrr\n",4);
}

static void    push(t_stack **dest, t_stack **src)
{
	t_stack	*push_node;
	
	if (*src == NULL)
		return ;
	push_node = *src;
	*src = (*src)->next;
	push_node->next = NULL;
	if (*dest == NULL)
		*dest = push_node;
	else
	{
		push_node->next = (*dest);
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}

void	pa(t_stack **a, t_stack **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1,"pa\n",3);
}

void	pb(t_stack **b, t_stack **a, bool checker)
{
	push(b, a);
	if (!checker)
		write(1,"pb\n",3);
}