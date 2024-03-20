/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:25:41 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/20 16:23:53 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*find_min(t_stack *stack)
{
	t_node	*min_node;
	t_node	*current;
	int		min;

	if (!stack)
		return (NULL);
	min_node = NULL;
	min = INT_MAX;
	current = stack->head;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

t_node	*find_max(t_stack *stack)
{
	t_node	*max_node;
	t_node	*current;
	int		max;

	if (!stack)
		return (NULL);
	max_node = NULL;
	max = INT_MIN;
	current = stack->head;
	while (current)
	{
		if (current->value > max)
		{
			max = current->value;
			max_node = current;
		}
		current = current->next;
	}
	return (max_node);
}

t_node	*find_last(t_stack *stack)
{
	t_node	*last;

	if (!stack || !stack->head)
		return (NULL);
	last = stack->head;
	while (last->next)
		last = last->next;
	return (last);
}

void	min_max(t_stack *stack, int *min_rank, int *max_rank)
{
	t_node	*current;

	if (!stack)
		return ;
	current = stack->head;
	*min_rank = stack->head->rank;
	*max_rank = stack->head->rank;
	while (current)
	{
		if (*min_rank > current->rank)
			*min_rank = current->rank;
		else if (*max_rank < current->rank)
			*max_rank = current->rank;
		current = current->next;
	}
}

int	stack_len(t_stack *stack)
{
	int		i;
	t_node	*current;

	if (!stack || !(stack->head))
		return (0);
	i = 0;
	current = stack->head;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}
