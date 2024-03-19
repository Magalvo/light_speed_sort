/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:53:22 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/19 15:31:42 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node *get_best_friend(t_stack *a, int nbr)
{
	int		temp;
	t_node	*temp_node;
	t_node	*current;

	current = a->head;
	temp = INT_MAX;
	while (current)
	{
		if (current->value > nbr && current->value < temp)
		{
			temp = current->value;
			temp_node = current;
		}
		current = current->next;
	}
	return (temp_node);
}

void set_target_b(t_stack *a, t_stack *b)
{
	t_node *current;

	current = b->head;
	while (current)
	{
		current->target = get_best_friend(a, current->value);
		//printf("Bestie: %i\n", current->target->value);
		current = current->next;
	}
}
void	cost_analysis(t_stack *dst, t_stack *src)
{
	int		len_dst;
	int		len_src;
	t_node	*temp;

	temp = src->head;
	len_dst= stack_len(dst);
	len_src= stack_len(src);
	while(temp)
	{
		temp->cost = temp->index;
		if (!(temp->above_median))
			temp->cost = len_src - (temp->index);
		if (temp->target->above_median)
			temp->cost += temp->target->index;
		else
			temp->cost += len_dst - (temp->target->index);
		//printf("ValueA: %i\t\t", temp->value);
		//printf("Cost: %i\n", temp->cost);
		temp = temp->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	int		cheapest_val;
	t_node	*cheapest_node;
	t_node	*current;

	if (!stack || !(stack->head))
		return ;
	current = stack->head;
	cheapest_val = INT_MAX;
	while (current)
	{
		if (current->cost < cheapest_val)
		{
			cheapest_val = current->cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	cheapest_node->cheapest = true;
	stack->cheapest = cheapest_node;
}

t_node	*get_cheapest(t_stack *stack)
{
	t_node	*temp;

	if(!stack)
		return (NULL);
	temp = stack->head;
	while (temp)
	{
		if(temp->cheapest)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
