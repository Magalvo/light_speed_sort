/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_turk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:36:22 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/20 16:38:24 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_both_turk(t_stack *a, t_stack *b, t_node *cheapest_node)
{
	while (b->head != cheapest_node->target && a->head != cheapest_node)
		rr(a, b, false);
	current_index(a);
	current_index(b);
}

void	reverse_rotate_both_turk(t_stack *a, t_stack *b, t_node *cheapest_node)
{
	while (b->head != cheapest_node->target && a->head != cheapest_node)
		rrr(a, b, false);
	current_index(a);
	current_index(b);
}
