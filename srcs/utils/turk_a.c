/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:57:26 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/19 19:04:05 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	a_turk_target(t_stack *a, t_stack *b)
{
	t_node	*current_a;
	t_node	*current_b;
	t_node 	*target;
	int		best;

	current_a = a->head;
	current_b = b->head;
	while(current_b)
	{
		best = INT_MIN;
		while (current_b)
		{
			if (current_b->value > current_b->value && current_b->value < best)
			{
				best = current_b->value;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best == INT_MIN)
			current_a->target = find_max(b);
		else
			current_a->target = target;
		current_a = current_a->next;
	}
}

void	move_turk_ab(t_stack *a, t_stack *b)
{
	t_node *cheapest_node;

	cheapest_node = get_cheapest(a);
	// printf("Cheap: %i\n", cheapest_node->value);
	if (cheapest_node->above_median && cheapest_node != b->head && cheapest_node->target->above_median && cheapest_node->target != a->head)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target->above_median) && cheapest_node->target != a->head && cheapest_node != b->head)
		reverse_rotate_both(a, b, cheapest_node);
	push_prep(a, cheapest_node, 'a');
	push_prep(b, (a)->cheapest->target, 'b');
	pb(b, a, false);
}

void	cost_analysis_turk(t_stack *a, t_stack *b)
{
	int		len_a;
	int		len_b;
	t_node	*current;

	len_a = stack_len(a);
	len_b = stack_len(b);
	current = a->head;
	while (current)
	{
		current->cost = current->index;
		if (!(current->above_median))
			current->cost = len_a - (current->index);
		if (current->target->above_median)
			current->cost += current->target->index;
		else
			current->cost += len_b - (current->target->index);
		current = current->next;
	}

}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	a_turk_target(a, b);
	cost_analysis_turk(a, b);
	set_cheapest(a);
}
