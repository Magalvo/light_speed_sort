/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:31:47 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/25 11:33:04 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack *a)
{
	t_node	*biggest_node;

	if (stack_len(a) == 2)
	{
		sa(a, false);
		return ;
	}
	biggest_node = find_max(a);
	if (biggest_node == (a)->head)
		ra(a, false);
	else if ((a)->head->next == biggest_node)
		rra(a, false);
	if ((a)->head->value > (a)->head->next->value)
		sa(a, false);
}

int	top_cost(t_stack *stack, t_node *small)
{
	int		cost;
	t_node	*current;

	cost = 0;
	current = stack->head;
	while (current != small)
	{
		cost++;
		current = current->next;
	}
	return (cost);
}

void	sort_ten(t_stack *a, t_stack *b)
{
	t_node	*small;
	t_node	*first;

	first = find_min(a);
	while (!stack_sorted(a))
	{
		small = find_min(a);
		if (stack_len(a) <= 3)
			sort_three(a);
		else
		{
			if (a->size / 2 > top_cost((a), small))
				while (!stack_sorted(a) && (a)->head != small)
					ra(a, false);
			else
				while (!stack_sorted(a) && (a)->head != small)
					rra(a, false);
			if (!stack_sorted(a))
				pb(b, a, false);
		}
	}
	while (a->head != first)
		pa(a, b, false);
}
