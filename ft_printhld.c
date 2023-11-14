/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhld.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:43:34 by ymomen            #+#    #+#             */
/*   Updated: 2023/11/14 15:12:54 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhld(const char *format, char *holder, int *hldsize, int *count)
{
	if (*hldsize == LIMT || *format == '%')
	{
		*count += write(STDUT, holder, *hldsize);
		if (*hldsize == LIMT)
			*count += write(STDUT, format, 1);
		*hldsize = 0;
		ft_bzero(holder, LIMT);
	}
	else
	{
		holder[*hldsize] = *format;
		*hldsize += 1;
	}
}
