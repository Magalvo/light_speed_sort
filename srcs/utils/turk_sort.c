/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:35:52 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/19 16:44:42 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


void	turk_sort(t_stack *a, t_stack *b)
{
	int	len_a;

	len_a = stack_len(a);
	if (len_a-- > 3 && stack_sorted(a))
		pb(b, a, false);
	if (len_a-- > 3 && stack_sorted(a))
		pb(b, a, false);
	while (!stack_sorted(a) && len_a-- > 3)
	{
		init_nodes_a(a, b);
		move_turk_ab(a, b);
	}
	sort_three(a);
	while (b)
	{
		init_nodes_b(a, b);
		move_turk_ba(a, b);
	}
}
