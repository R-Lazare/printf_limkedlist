/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:11:09 by rluiz             #+#    #+#             */
/*   Updated: 2023/06/03 17:08:40 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_char(va_list ap, int *count)
{
	char	c;

	c = (char)va_arg(ap, int);
	write(1, &c, 1);
	(*count)++;
}

void	handle_str(va_list ap, int *count)
{
	char	*s;
	int		len;

	s = va_arg(ap, char *);
	len = ft_strlen(s);
	write(1, s, len);
	(*count) += len;
}

void	handle_ptr(va_list ap, int *count)
{
	void	*p;

	p = va_arg(ap, void *);
	write(1, "0x", 2);
	ft_print_ptr((unsigned long long)p, "0123456789abcdef");
	(*count) += (16);
}

void	handle_int(va_list ap, int *count)
{
	int		d;
	char	*d_str;

	d = va_arg(ap, int);
	d_str = ft_itoa(d);
	write(1, d_str, ft_strlen(d_str));
	(*count) += ft_strlen(d_str);
	free(d_str);
}
