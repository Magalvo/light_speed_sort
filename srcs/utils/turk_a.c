/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:57:26 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/21 17:24:10 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void a_turk_target(t_stack *a, t_stack *b)
{
	t_node *current_a;
	t_node *current_b;
	t_node *target;
	int best;

	current_a = a->head;
	while (current_a)
	{
		best = INT_MIN;
		current_b = b->head;
		while (current_b)
		{
			if (current_b->value < current_a->value && current_b->value > best)
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

void move_turk_ab(t_stack *a, t_stack *b)
{
	t_node *cheapest_node;

	cheapest_node = a->cheapest;
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both_turk(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target->above_median))
		reverse_rotate_both_turk(a, b, cheapest_node);
	push_prep(a, cheapest_node, 'a');
	push_prep(b, cheapest_node->target, 'b');
	pb(b, a, false);
}

void cost_analysis_turk(t_stack *dst, t_stack *src)
{
	int len_dst;
	int len_src;
	t_node *temp;

	temp = src->head;
	len_dst = stack_len(dst);
	len_src = stack_len(src);
	while (temp)
	{
		temp->cost = temp->index;
		if (!(temp->above_median))
			temp->cost = len_src - (temp->index);
		if (temp->target->above_median)
			temp->cost += temp->target->index;
		else
			temp->cost += len_dst - (temp->target->index);
		temp = temp->next;
	}
}

void init_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	a_turk_target(a, b);
	cost_analysis_turk(b, a);
	set_cheapest(a);
}
