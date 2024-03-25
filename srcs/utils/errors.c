/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:32:23 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/25 11:22:52 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_all(char **in)
{
	int	ctd;

	ctd = 0;
	while (in[ctd])
		free(in[ctd++]);
	free(in);
}

void	free_stack(t_stack *stack, char **av, bool flag)
{
	t_node	*tmp;
	t_node	*current;

	if (flag)
		free_all(av);
	if (!stack)
		return ;
	current = (stack)->head;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	stack = NULL;
}

int	error_syntax(char *str_nbr)
{
	if (!(*str_nbr == '+' || *str_nbr == '-' || (*str_nbr >= '0'
				&& *str_nbr <= '9')))
		return (ft_putstr_fd("Error\n", 2), 1);
	if ((*str_nbr == '+' || *str_nbr == '-') && !(str_nbr[1] >= '0'
			&& str_nbr[1] <= '9'))
		return (ft_putstr_fd("Error\n", 2), 1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (ft_putstr_fd("Error\n", 2), 1);
	}
	return (0);
}

int	error_repetition(t_stack *a, int nbr)
{
	t_node	*current;

	if (!a || !a->head)
		return (0);
	current = a->head;
	while (current)
	{
		if (current->value == nbr)
			return (ft_putstr_fd("Error\n", 2), 1);
		current = current->next;
	}
	return (0);
}

void	error_free(t_stack *a, char **argv, bool flag_argc_2)
{
	free_stack(a, argv, flag_argc_2);
	exit(1);
}
