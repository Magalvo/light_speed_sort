/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:39:37 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/20 16:37:47 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*second_to_last;
	t_node	*last;

	if (!(stack)->head || !(stack)->head->next)
		return ;
	last = (stack)->head;
	second_to_last = NULL;
	while (last->next)
	{
		second_to_last = last;
		last = last->next;
	}
	if (second_to_last)
		second_to_last->next = NULL;
	last->next = (stack)->head;
	(stack)->head->prev = last;
	last->prev = NULL;
	(stack)->head = last;
	stack->tail = second_to_last;
}

void	rra(t_stack *a, bool print)
{
	reverse_rotate(a);
	if (!print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *b, bool print)
{
	reverse_rotate(b);
	if (!print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		ft_putstr_fd("rrr\n", 1);
}

void	reverse_rotate_both(t_stack *a, t_stack *b, t_node *cheapest_node)
{
	while (a->head != cheapest_node->target && b->head != cheapest_node)
		rrr(a, b, false);
	current_index(a);
	current_index(b);
}
