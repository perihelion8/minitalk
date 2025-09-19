/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:58:42 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/19 02:03:01 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const uint8_t	*srcb;
	uint8_t			*dstb;

	srcb = (const uint8_t *) src;
	dstb = (uint8_t *) dst;
	while (n--)
		*dstb++ = *srcb++;
	return (dst);
}
