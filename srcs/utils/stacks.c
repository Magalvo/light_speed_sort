/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:52:19 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/25 10:30:43 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	append_node(t_stack *stack, int n)
{
	t_node	*node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->value = n;
	node->next = NULL;
	node->prev = stack->tail;
	if (!stack->head)
		stack->head = node;
	else
		stack->tail->next = node;
	stack->tail = node;
	stack->size++;
}

void	current_index(t_stack *stack)
{
	int		i;
	int		median;
	t_node	*current;

	i = 0;
	if (!stack || !(stack->head))
		return ;
	median = stack_len(stack) / 2;
	current = stack->head;
	while (current)
	{
		current->index = i;
		if (i <= median)
			current->above_median = true;
		else
			current->above_median = false;
		current = current->next;
		i++;
	}
}

bool	stack_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !(stack->head))
		return (true);
	current = stack->head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

void	push_prep(t_stack *stack, t_node *top_node, char stk_name)
{
	while (stack->head != top_node)
	{
		if (stk_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stk_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

void	move_b_a(t_stack *a, t_stack *b)
{
	t_node	*cheapest_node;

	cheapest_node = b->cheapest;
	if (cheapest_node->above_median && cheapest_node != b->head
		&& cheapest_node->target->above_median
		&& cheapest_node->target != a->head)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median)
		&& cheapest_node->target != a->head && cheapest_node != b->head)
		reverse_rotate_both(a, b, cheapest_node);
	push_prep(a, (b)->cheapest->target, 'a');
	push_prep(b, cheapest_node, 'b');
	pa(a, b, false);
}
