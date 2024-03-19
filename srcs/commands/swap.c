/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:40:03 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/18 16:23:14 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!stack || !(stack->head->next) || !(stack->head))
		return ;
	first = stack->head;
	second = stack->head->next;
	third = second->next;

	first->next = third;
	first->prev = second;

	second->next = first;
	second->prev = NULL;

	if (third)
		third->prev = first;
	stack->head = second;
}

void	sa(t_stack *a, bool print)
{
	swap(a);
	if (!print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b, bool print)
{
	swap(b);
	if (!print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_putstr_fd("ss\n", 1);
}
