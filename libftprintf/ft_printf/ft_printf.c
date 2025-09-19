/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 20:40:48 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/19 03:11:19 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static void	initialize_flag(t_flag *flag)
{
	flag->pad_positive = false;
	flag->show_sign = false;
	flag->alternate_form = false;
	flag->left_align = false;
	flag->zero_fill = false;
	flag->width = -1;
	flag->precision = -1;
}

static const char	*printf_flags(const char *s, t_flag *flag)
{
	initialize_flag(flag);
	while (*s && ft_strchr(" +#-0", *s) != NULL)
	{
		if (*s == ' ')
			flag->pad_positive = true;
		else if (*s == '+')
			flag->show_sign = true;
		else if (*s == '#')
			flag->alternate_form = true;
		if (*s == '-')
			flag->left_align = true;
		else if (*s == '0')
			flag->zero_fill = true;
		s++;
	}
	flag->width = ft_atoi(s);
	while (ft_isdigit(*s))
		s++;
	if (*s == '.')
	{
		flag->precision = ft_atoi(++s);
		while (ft_isdigit(*s))
			s++;
	}
	return (s);
}

static int	printf_arg(const char *s, va_list args, t_flag *flag)
{
	if (*s == 'c')
		return (ft_printf_c(va_arg(args, int), flag));
	else if (*s == 's')
		return (ft_printf_s(va_arg(args, char *), flag));
	else if (*s == 'p')
		return (ft_printf_p(va_arg(args, void *), flag));
	else if (*s == 'd' || *s == 'i')
		return (ft_printf_d(va_arg(args, int), flag));
	else if (*s == 'u')
		return (ft_printf_u(va_arg(args, t_uint), flag));
	else if (*s == 'x')
		return (ft_printf_x(va_arg(args, int), 0, flag));
	else if (*s == 'X')
		return (ft_printf_x(va_arg(args, int), 1, flag));
	else if (*s == '%')
		return (ft_printf_c('%', flag));
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	t_flag		flag;
	const char	*tmp;
	int			ret;
	int			len;

	va_start(args, s);
	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			tmp = printf_flags(s + 1, &flag);
			ret = printf_arg(tmp, args, &flag);
			if (ret != -1)
			{
				s = tmp + 1;
				len += ret;
			}
		}
		else
			len += write(1, s++, 1);
	}
	va_end(args);
	return (len);
}
