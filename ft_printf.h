/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:15:37 by ymomen            #+#    #+#             */
/*   Updated: 2023/11/14 02:05:03 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define LIMT 500
# define STDUT 1

# include <stdarg.h>
# include <unistd.h>

extern int	g_errcheck;
/* FUNCTIONS */
void	ft_print_add(void *ptr, int *count);
void	ft_putnbr_base(int nbr, const char *format, int *count);
void	ft_putunbr(unsigned int n, int *count);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_managecase(va_list arg, const char *format, int *count);
void	ft_bzero(void *s, size_t n);
int		ft_helper(const char *format, int *count, va_list arg);
void	ft_printhld(const char *format,	char *holder, int *hldsize, int *count);
size_t	ft_strlens(char *str);
void	ft_putnbr(int n, int *count);
void	ft_putchar(char c, int *count);
int		ft_printf(const char *format, ...);

#endif /*FT-PRINTF*/