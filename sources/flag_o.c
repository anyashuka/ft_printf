/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:14:20 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/03 20:48:53 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

static uintmax_t	length_o(va_list *ap, t_print *arg)
{
	if (arg->length == 2 && arg->format[arg->i] != 'O')
		return ((unsigned char)va_arg(*ap, uintmax_t));
	else if (arg->length == 3 && arg->format[arg->i] != 'O')
		return ((unsigned short int)va_arg(*ap, uintmax_t));
	else if (arg->length == 5 || arg->format[arg->i] == 'O')
		return ((unsigned long)va_arg(*ap, uintmax_t));
	else if (arg->length == 6)
		return ((unsigned long long)va_arg(*ap, uintmax_t));
	else if (arg->length == 4)
		return ((uintmax_t)va_arg(*ap, uintmax_t));
	else if (arg->length == 7)
		return ((size_t)va_arg(*ap, uintmax_t));
	else
		return ((unsigned int)va_arg(*ap, uintmax_t));
	//	return (va_arg(*ap, uintmax_t));
}


void	flag_o(va_list *ap, t_print *arg)
{
	uintmax_t	nb;
	intmax_t	len;
	t_out		out;

	nb = length_o(ap, arg);
	(nb == 0 && !arg->precision_field) ? arg->ishash = 0 : 0;
	len = ft_count(nb);
	out.value = (nb == 0 && arg->precision_field == 1) ? ft_strdup("\0") \
		: ft_strdup(ft_utoa_base(nb, 8));
	out.string = ft_strdup(out.value);
	out.string = combine(arg, &out, len);
	arg->ret += ft_strlen(out.string);
	ft_putstr(out.string);
	ft_strdel(&out.value);
	ft_strdel(&out.string);
}
