/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:36:31 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/19 02:01:40 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *m, int c, size_t n)
{
	unsigned char	*mb;

	mb = (unsigned char *)m;
	while (n--)
		*mb++ = (unsigned char) c;
	return (m);
}
