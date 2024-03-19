/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:22:45 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/15 15:42:03 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	bubble_sort(int arr[], int n)
{
	int		i;
	int 	j;
	int		temp;

	i = 0;
	while (i < n-1)
	{
		j = 0;
		while (j < n-i-1)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	assign_ranks(t_stack *stack, int sorted_values[], int len)
{
	t_node	*current;
	int		i;

	current = stack->head;
	while (current != NULL)
	{
		i = 0;
		while(i < len)
		{
			if (current->value == sorted_values[i])
			{
				current->rank = i + 1;
				break;
			}
			i++;
		}
		current = current->next;
	}
}

int	ranking(t_stack *stack)
{
	int		len;
	int		index;
	int		*arr;
	t_node	*current;

	index = 0;
	current = stack->head;
	len = stack_len(stack);
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (0);
	while (current)
	{
		arr[index++] = current->value;
		current = current->next;
	}
	bubble_sort(arr, len);
	assign_ranks(stack, arr, len);
	free(arr);
	return (0);
}
