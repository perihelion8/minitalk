/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 20:27:31 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/19 03:13:02 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include <stdarg.h>
# include <stdbool.h>
# include "libft.h"
# include "printf.h"

typedef struct s_flag
{
	bool	pad_positive;
	bool	show_sign;
	bool	alternate_form;
	bool	left_align;
	bool	zero_fill;
	int		width;
	int		precision;
}	t_flag;

typedef struct s_numprop
{
	bool	upper_x;
	char	width_char;
	int		digit_len;
	int		prec_len;
	int		core_len;
	int		total_len;
}	t_numprop;

int		ft_printf_c(char c, t_flag *flag);
int		ft_printf_s(const char *s, t_flag *flag);
int		ft_printf_d(int n, t_flag *flag);
int		ft_printf_u(t_uint n, t_flag *flag);
int		ft_printf_x(t_uint n, bool is_upper, t_flag *flag);
int		ft_printf_p(void *n, t_flag *flag);
int		ft_printf_int_max(int a, int b);
void	ft_printf_repeat_c(char c, int n);

#endif
