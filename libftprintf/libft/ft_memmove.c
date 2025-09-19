/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:13:54 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/19 02:04:31 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	const uint8_t	*srcb;
	uint8_t			*dstb;

	srcb = (const uint8_t *) src;
	dstb = (uint8_t *) dst;
	if (dstb > srcb)
	{
		dstb += n - 1;
		srcb += n - 1;
		while (n--)
			*dstb-- = *srcb--;
	}
	else
		while (n--)
			*dstb++ = *srcb++;
	return (dst);
}
