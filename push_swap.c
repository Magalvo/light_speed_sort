/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:27:27 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/25 13:05:24 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	print_list(t_stack *stack)
{
	while (stack->head->next)
	{
		printf("Value: %d\n", stack->head->value);
		stack->head = stack->head->next;
	}
}

int	main(int argc, char **argv)
{
	static t_stack	a;
	static t_stack	b;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_a(&a, argv, argc == 2);
	}
	else
		init_a(&a, argv + 1, argc == 2);
	if (a.head->value == 418 && a.size == 1)
		ft_putstr_fd("Im a sorted tea pot :)\n", 1);
	if (!stack_sorted(&a))
	{
		if (a.size == 3 || a.size == 2)
			sort_three(&a);
		else if (a.size <= 75 && a.size > 5)
			turk_sort(&a, &b);
		else
			quick_friend(&a, &b);
	}
	free_stack(&a, argv, argc == 2);
	return (0);
}
