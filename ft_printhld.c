/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhld.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:43:34 by ymomen            #+#    #+#             */
/*   Updated: 2023/11/13 23:14:40 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhld(const char *format, char *holder, int *hldsize, int *count)
{
	int	g_errcheck;

	if (*hldsize == LIMT || *format == '%')
	{
		*count += write(STDUT, holder, *hldsize);
		if (*format + 1 == '\0')
			g_errcheck = -1;
		*hldsize = 0;
		ft_bzero(holder, LIMT);
	}
	else
	{
		holder[*hldsize] = *format;
		*hldsize += 1;
	}
}
