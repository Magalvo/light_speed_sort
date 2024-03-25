/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:17:24 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/21 17:24:10 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!(stack)->head || !(stack)->head->next)
		return ;
	first = (stack)->head;
	(stack)->head = (stack)->head->next;
	(stack)->head->prev = NULL;
	last = first;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	stack->tail = first;
}

void	ra(t_stack *a, bool print)
{
	rotate(a);
	if (!print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *b, bool print)
{
	rotate(b);
	if (!print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_putstr_fd("rr\n", 1);
}

void	rotate_both(t_stack *a, t_stack *b, t_node *cheapest_node)
{
	while (a->head != cheapest_node->target && b->head != cheapest_node)
		rr(a, b, false);
	current_index(a);
	current_index(b);
}
