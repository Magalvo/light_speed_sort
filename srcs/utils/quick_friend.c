/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_friend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:36:04 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/20 16:24:38 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_ranks(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		printf("Value: %d\n", current->rank);
		current = current->next;
	}
}

void	quick_friend(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	ranking(a);
	min_max(a, &min, &max);
	while (!stack_sorted(a))
	{
		if (stack_len(a) <= 10 || max - min < 10)
		{
			sort_ten(a, b);
			break ;
		}
		a_sort(a, b, max, min);
	}
	while (stack_len(b) != 0)
	{
		b_sort(a, b);
	}
	min_on_top(a);
}
