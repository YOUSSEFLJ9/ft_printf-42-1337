/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 02:14:18 by ymomen            #+#    #+#             */
/*   Updated: 2023/11/14 02:26:47 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_baseadd(unsigned long long nbr, char *base,
	int *count)
{
	if (nbr >= 16)
	{
		print_baseadd(nbr / 16, base, count);
		print_baseadd(nbr % 16, base, count);
	}
	if (nbr < 16)
	{
		*count += write(STDUT, &base[nbr], 1);
	}
}

void	ft_print_add(void *ptr, int *count)
{
	unsigned long long	add;
	char				*base;

	base = "0123456789abcdef";
	add = (unsigned long long) ptr;
	*count += write(STDUT, "0x", 2);
	print_baseadd(add, base, count);
}
