/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:27:27 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/21 18:44:56 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void print_list(t_stack *stack)
{
	while (stack->head->next)
	{
		printf("Value: %d\n", stack->head->value);
		stack->head = stack->head->next;
	}
}

int main(int argc, char **argv)
{
	static t_stack a;
	static t_stack b;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		return (ft_putstr_fd("Errorp\n", 2), 0);
	}
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_a(&a, argv + 1, argc == 2);
	if (!stack_sorted(&a))
	{
		if (stack_len(&a) == 2)
			sa(&a, false);
		else if (stack_len(&a) == 3)
			sort_three(&a);
		else if (stack_len(&a) <= 75)
			turk_sort(&a, &b);
		else
			quick_friend(&a, &b);
	}
	free_stack(&a, argv, argc == 2);
	return (0);
}
