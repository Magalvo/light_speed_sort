/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:54:04 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/07 16:54:40 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*ft_strdup(char *src)
{
	unsigned char	*cpy;
	size_t			i;
	size_t			len;

	len = ft_strlen(src);
	i = 0;
	cpy = (unsigned char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return ((char *)cpy);
}