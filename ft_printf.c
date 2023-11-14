/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:15:10 by ymomen            #+#    #+#             */
/*   Updated: 2023/11/14 15:00:09 by ymomen           ###   ########.fr       */
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
	ft_helper(format, &count, arg);
	va_end (arg);
	return (count);
}

void	ft_helper(const char *format, int *count, va_list arg)
{
	int			hldsize;
	char		holder[LIMT];

	hldsize = 0;
	while (*format != '\0')
	{
		if (*format != '%')
			ft_printhld(format, holder, &hldsize, count);
		else
		{
			ft_printhld(format, holder, &hldsize, count);
			if (*(format + 1) == '\0')
				break ;
			format++;
			ft_managecase(arg, format, count);
		}
		format++;
	}
	if (hldsize != 0)
		*count += write(STDUT, holder, hldsize);
}
