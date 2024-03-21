/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:35:52 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/21 17:24:10 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void min_on_top(t_stack *a)
{
	while (a->head->value != find_min(a)->value)
	{
		if (find_min(a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void turk_sort(t_stack *a, t_stack *b)
{
	int len_a;

	len_a = stack_len(a);
	if (len_a-- > 3 && !stack_sorted(a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(a))
	{
		init_nodes_a(a, b);
		move_turk_ab(a, b);
	}
	sort_three(a);
	while (stack_len(b) != 0)
	{
		init_nodes_b(a, b);
		move_turk_ba(a, b);
	}
	current_index(a);
	min_on_top(a);
}
