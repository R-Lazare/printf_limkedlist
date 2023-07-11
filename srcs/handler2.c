/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:12:20 by rluiz             #+#    #+#             */
/*   Updated: 2023/06/09 16:29:40 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_uint(va_list ap, int *count)
{
	unsigned int	u;
	char			*u_str;

	u = va_arg(ap, unsigned int);
	u_str = ft_utoa(u);
	write(1, u_str, ft_strlen(u_str));
	(*count) += ft_strlen(u_str);
	free(u_str);
}

void	handle_hex(va_list ap, int *count, int uppercase)
{
	unsigned int	x;
	char			*x_str;

	x = va_arg(ap, unsigned int);
	if (uppercase)
		ft_putnbr_base(x, "0123456789ABCDEF");
	else
		ft_putnbr_base(x, "0123456789abcdef");
	x_str = ft_utoa(x);
	(*count) += ft_strlen(x_str);
	free(x_str);
}

t_list	*creat_lst(char *src)
{
	t_list	*list;

	list = ft_lstnew(src);
	return (list);
}

int	count_flags(char *format)
{
	int		i;
	int		count;
	char	*valid_flags;

	i = 0;
	count = 0;
	valid_flags = "cspdiuxX%";
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr(valid_flags, format[i + 1]))
			count++;
		i++;
	}
	return (count);
}

int	count_percent(char *format)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count++;
		i++;
	}
	return (count);
}
