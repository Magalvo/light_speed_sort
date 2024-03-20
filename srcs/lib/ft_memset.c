/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:07:15 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/20 16:32:28 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pos;
	unsigned char	ac;

	ac = (unsigned char)c;
	pos = (unsigned char *)b;
	while (len--)
		*pos++ = ac;
	return (b);
}
