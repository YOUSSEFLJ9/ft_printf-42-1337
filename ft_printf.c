/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:15:10 by ymomen            #+#    #+#             */
/*   Updated: 2023/11/13 23:14:31 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	arg;

	count = 0;
	va_start (arg, format);
	if (write(STDUT, "", 0) == -1 || !format)
		return (-1);
	if (!ft_helper(format, &count, arg))
		return (-1);
	va_end (arg);
	return (count);
}

int	ft_helper(const char *format, int *count, va_list arg)
{
	int			hldsize;
	char		holder[LIMT];
	int			g_errcheck;

	g_errcheck = 1;
	hldsize = 0;
	while (*format != '\0')
	{
		if (*format != '%')
			ft_printhld(format, holder, &hldsize, count);
		else
		{
			ft_printhld(format, holder, &hldsize, count);
			if (g_errcheck == -1)
				return (0);
			format++;
			ft_managecase(arg, format, count);
		}
		format++;
	}
	if (hldsize != 0)
		*count += write(STDUT, holder, hldsize);
	return (1);
}
