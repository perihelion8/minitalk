/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:49:03 by a                 #+#    #+#             */
/*   Updated: 2025/09/19 02:06:50 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *m1, const void *m2, size_t n)
{
	const uint8_t	*m1b;
	const uint8_t	*m2b;
	size_t			i;

	if (n == 0)
		return (0);
	m1b = (const uint8_t *) m1;
	m2b = (const uint8_t *) m2;
	i = 0;
	while (m1b[i] == m2b[i] && i + 1 < n)
		i++;
	return (m1b[i] - m2b[i]);
}
