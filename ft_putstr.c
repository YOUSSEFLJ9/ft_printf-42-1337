/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:16:05 by ymomen            #+#    #+#             */
/*   Updated: 2023/11/13 23:14:44 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlens(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	count;
	char	*str;

	str = (char *) s;
	count = 0;
	while (count < n)
	{
		str[count] = '\0';
		count++;
	}
}

void	ft_putstr(char *str, int *count)
{
	if (!str)
	{
		*count += write(STDUT, "(null)", 6);
		return ;
	}
	*count += write(STDUT, str, ft_strlens(str));
}
