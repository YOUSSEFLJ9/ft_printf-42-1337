/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:19:32 by ymomen            #+#    #+#             */
/*   Updated: 2023/11/14 02:06:43 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_base(unsigned int nbr, char *base,
	unsigned int len, int *count)
{
	if (nbr >= len)
	{
		print_base(nbr / len, base, len, count);
		print_base(nbr % len, base, len, count);
	}
	if (nbr < len)
	{
		*count += write(1, &base[nbr], 1);
	}
}

void	ft_putnbr_base(int nbr, const char *format, int *count)
{
	unsigned int	new_nb;
	char			*base_upper;
	char			*base_lower;

	base_upper = "0123456789ABCDEF";
	base_lower = "0123456789abcdef";
	new_nb = nbr;
	if (*format == 'X')
		print_base(new_nb, base_upper, 16, count);
	else
		print_base(new_nb, base_lower, 16, count);
}
