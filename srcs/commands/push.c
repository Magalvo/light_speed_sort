/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:39:10 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/19 15:52:25 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_stack *dst, t_stack *src)
{
	t_node	*push_node;

	if (!src || !(src->head))
		return ;
	push_node = src->head;
	src->head = src->head->next;
	if (src->head)
		(src)->head->prev = NULL;
	if (dst->head)
		dst->head->prev = push_node;
	push_node->next = dst->head;
	push_node->prev = NULL;
	dst->head = push_node;
	dst->size++;
	src->size--;
}

void	pa(t_stack *a, t_stack *b, bool print)
{
	push(a, b);
	if (!print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *b, t_stack *a, bool print)
{
	push(b, a);
	if (!print)
		ft_putstr_fd("pb\n", 1);
}
