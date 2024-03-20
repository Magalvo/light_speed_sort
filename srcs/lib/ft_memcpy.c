/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:52:59 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/20 16:32:22 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*altdest;
	unsigned char	*altsrc;

	altdest = (unsigned char *)dest;
	altsrc = (unsigned char *)src;
	if (!altdest && !altsrc)
		return (NULL);
	while (n-- > 0)
	{
		*altdest = *altsrc;
		altdest++;
		altsrc++;
	}
	return (dest);
}
