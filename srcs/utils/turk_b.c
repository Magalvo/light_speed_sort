/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:57:37 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/20 00:17:52 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void b_turk_target(t_stack *a, t_stack *b)
{
	t_node *current_a;
	t_node *current_b;
	t_node *target;
	int best;

	current_a = a->head;
	current_b = b->head;
	while (current_b)
	{
		best = INT_MAX;
		while (current_a)
		{
			if (current_a->value > current_b->value && current_a->value < best)
			{
				best = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best == INT_MAX)
			current_b->target = find_min(a);
		else
			current_b->target = target;
		current_b = current_b->next;
	}
}

t_node *get_high_friend(t_stack *stack, int nbr)
{
	int best;
	t_node *current;
	t_node *best_node;

	current = stack->head;
	best = INT_MAX;
	while (current)
	{
		if (current->value > nbr && current->value < best)
		{
			best = current->value;
			best_node = current;
		}
		current = current->next;
	}
	if (best == INT_MAX)
		best_node = find_min(stack);
	return (best_node);
}

void move_turk_ba(t_stack *a, t_stack *b)
{
	push_prep(a, b->head->target, 'a');
	pa(a, b, false);
}

void init_nodes_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	b_turk_target(a, b);
}
