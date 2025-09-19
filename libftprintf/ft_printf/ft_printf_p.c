/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:14:59 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/19 03:11:47 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	digits_count(unsigned long n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		count++;
		n /= 16;
	}
	return (count);
}

static void	init_num_prop(unsigned long n, t_numprop *prop, t_flag *flag)
{
	prop->digit_len = digits_count(n) + 2;
	if (n == 0)
		prop->digit_len = 5;
	prop->total_len = ft_printf_int_max(prop->digit_len, flag->width);
	if (flag->precision != -1)
		prop->width_char = ' ';
	else if (flag->zero_fill)
		prop->width_char = '0';
	else
		prop->width_char = ' ';
}

static void	puthex(unsigned long n, char *hex)
{
	if (n >= 16)
		puthex(n / 16, hex);
	ft_putchar_fd(hex[n % 16], 1);
}

static int	print_core(unsigned long n, int digit_len, int zero_fill_total_len)
{
	int	len;

	if (n == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	len = zero_fill_total_len;
	ft_printf_repeat_c('0', zero_fill_total_len);
	len += digit_len;
	puthex(n, "0123456789abcdef");
	return (len);
}

int	ft_printf_p(void *ptr, t_flag *flag)
{
	unsigned long	n;
	t_numprop		prop;
	int				delta;

	n = (unsigned long)ptr;
	init_num_prop(n, &prop, flag);
	if (prop.total_len > prop.digit_len)
	{
		if (flag->left_align)
		{
			print_core(n, prop.digit_len, 0);
			ft_printf_repeat_c(' ', prop.total_len - prop.digit_len);
		}
		else
		{
			delta = prop.total_len - prop.digit_len;
			if (prop.width_char == '0')
				return (print_core(n, prop.digit_len, delta));
			ft_printf_repeat_c(prop.width_char, delta);
			print_core(n, prop.digit_len, 0);
		}
		return (flag->width);
	}
	return (print_core(n, prop.digit_len, 0));
}
