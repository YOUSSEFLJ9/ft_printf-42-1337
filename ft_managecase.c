/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_managecase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:45:13 by ymomen            #+#    #+#             */
/*   Updated: 2023/11/14 14:21:55 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_managecase(va_list arg, const char *format, int *count)
{
	if (*format == 'd' || *format == 'i' || *format == 'c')
	{
		if (*format == 'c')
			ft_putchar((char)va_arg(arg, int), count);
		else
			ft_putnbr((int) va_arg(arg, int), count);
	}
	else if (*format == 's')
		ft_putstr((char *) va_arg(arg, char *), count);
	else if (*format == '%')
		ft_putchar('%', count);
	else if (*format == 'u')
		ft_putunbr((unsigned int)va_arg(arg, unsigned int), count);
	else if (*format == 'X' || *format == 'x')
		ft_putnbr_base((unsigned int)va_arg(arg, unsigned int), format, count);
	else if (*format == 'p')
		ft_print_add((void *)va_arg(arg, void *), count);
	else
		ft_putchar(*format, count);
}
