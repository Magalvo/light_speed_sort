/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:53:10 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/20 16:22:07 by dde-maga         ###   ########.fr       */
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

void	a_sort(t_stack *a, t_stack *b, int max, int min)
{
	int	start_len;

	ranking(a);
	start_len = stack_len(a);
	a->median = start_len / 2;
	a->quarter = (a->median) / 2;
	while (stack_len(a) > (start_len - (a)->median) && stack_len(a) > 0)
	{
		if (a->head->rank <= a->median)
		{
			pb(b, a, false);
			if (b->head->rank <= a->quarter && stack_len(b) >= 2)
			{
				if (a->head->rank <= a->median)
					rb(b, false);
				else
					rr(a, b, false);
			}
		}
		else
			ra(a, false);
	}
	min_max(a, &min, &max);
}
