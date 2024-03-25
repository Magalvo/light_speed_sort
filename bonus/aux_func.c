/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:37:23 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/21 21:29:05 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

bool	move_it(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strcmp(str, "sa\n", 3))
		sa(a, true);
	else if (!ft_strcmp(str, "sb\n", 3))
		sb(b, true);
	else if (!ft_strcmp(str, "ra\n", 3))
		ra(a, true);
	else if (!ft_strcmp(str, "rra\n", 4))
		rra(a, true);
	else if (!ft_strcmp(str, "rb\n", 3))
		rb(b, true);
	else if (!ft_strcmp(str, "rrb\n", 4))
		rrb(b, true);
	else if (!ft_strcmp(str, "pa\n", 3))
		pa(a, b, true);
	else if (!ft_strcmp(str, "pb\n", 3))
		pb(b, a, true);
	else if (!ft_strcmp(str, "rrr\n", 4))
		rrr(a, b, true);
	else if (!ft_strcmp(str, "rr\n", 3))
		rr(a, b, true);
	else
		return (ft_putstr_fd("Error\n", 2), false);
	return (true);
}

void	checker(t_stack *a, t_stack *b)
{
	char	*line;

	if (stack_sorted(a) && b->size == 0)
	{
		ft_putstr_fd("OK\n", 1);
		return ;
	}
	while (true)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (!move_it(a, b, line))
			return (free(line));
		free(line);
	}
	if (stack_sorted(a) && b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
