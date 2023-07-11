/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:29:23 by rluiz             #+#    #+#             */
/*   Updated: 2023/06/09 15:55:01 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <ctype.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

t_list	*ft_splitflags(char *src);
t_list	*creat_lst(char *src);
int		count_flags(char *format);
void	print_and_count(va_list ap, char *flag, int *count);
void	handle_char(va_list ap, int *count);
void	handle_str(va_list ap, int *count);
void	handle_ptr(va_list ap, int *count);
void	handle_int(va_list ap, int *count);
void	handle_uint(va_list ap, int *count);
void	handle_hex(va_list ap, int *count, int uppercase);
void	handle_percent(int *count);
void	ft_putnbr_base(unsigned int nbr, char *base);
void	ft_putnbr_base_long(unsigned long long nbr, char *base);
void	ft_print_ptr(unsigned long long nbr, char *base);
char	*ft_utoa(unsigned int n);
int		count_flags(char *format);
int		ft_printf(const char *format, ...);
int		count_percent(char *format);

#endif