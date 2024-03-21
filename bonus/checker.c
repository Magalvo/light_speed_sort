/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:42:18 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/21 18:45:41 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int main(int argc, char **argv)
{
	static t_stack	a;
	static t_stack	b;

	if (argc == 1)
	{
		return (0);
	}
	if (argc == 2 && !argv[1][0])
	{
		return (ft_putstr_fd("Error\n", 2), 0);
	}
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_a(&a, argv + 1, argc == 2);
	if (!stack_sorted(&a))
		checker(&a, &b);
	free_stack(&a, argv, argc == 2);
	return (0);
}
