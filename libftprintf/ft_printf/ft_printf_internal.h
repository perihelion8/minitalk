/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 02:40:16 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/13 02:44:57 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include <stdarg.h>

# include "libft.h"
# include "ft_printf.h"

typedef struct s_flag
{
	t_byte	space;
	t_byte	plus;
	t_byte	hash;
	t_byte	minus;
	t_byte	zero;
	int		width;
	int		precision;
}	t_flag;

typedef struct s_numprop
{
	char	width_char;
	t_byte	upper_x;
	int		digit_len;
	int		prec_len;
	int		core_len;
	int		total_len;
}	t_numprop;

int		ft_printf_c(char c, t_flag *flag);
int		ft_printf_s(const char *s, t_flag *flag);
int		ft_printf_d(int n, t_flag *flag);
int		ft_printf_u(t_uint n, t_flag *flag);
int		ft_printf_x(t_uint n, t_byte is_upper, t_flag *flag);
int		ft_printf_p(void *n, t_flag *flag);
int		ft_printf_int_max(int a, int b);
void	ft_printf_repeat_c(char c, int n);

#endif
