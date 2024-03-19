/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:02:22 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/14 18:32:04 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*out;

	out = malloc(nmemb * size);
	if (out == NULL)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (out);
	ft_memset(out, 0, nmemb * size);
	return (out);
}