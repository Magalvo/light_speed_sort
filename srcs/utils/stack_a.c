/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:53:10 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/15 14:16:54 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_a(t_stack *a, char **argv, bool flag)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, flag);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			ft_putstr_fd("Error\n", 2);
			error_free(a, argv, flag);
		}	
		if (error_repetition(a, (int)nbr))
		{
			ft_putstr_fd("Error\n", 2);
			error_free(a, argv, flag);
		}
		append_node(a, (int)nbr);
		i++;
	}
}