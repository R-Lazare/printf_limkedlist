/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:41:16 by rluiz             #+#    #+#             */
/*   Updated: 2023/06/09 17:21:22 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_and_count(va_list ap, char *flag, int *count)
{
	if (ft_strncmp(flag, "%c", 2) == 0)
		handle_char(ap, count);
	else if (ft_strncmp(flag, "%s", 2) == 0)
		handle_str(ap, count);
	else if (ft_strncmp(flag, "%p", 2) == 0)
		handle_ptr(ap, count);
	else if (ft_strncmp(flag, "%d", 2) == 0 || ft_strncmp(flag, "%i", 2) == 0)
		handle_int(ap, count);
	else if (ft_strncmp(flag, "%u", 2) == 0)
		handle_uint(ap, count);
	else if (ft_strncmp(flag, "%x", 2) == 0)
		handle_hex(ap, count, 0);
	else if (ft_strncmp(flag, "%X", 2) == 0)
		handle_hex(ap, count, 1);
	else if (ft_strncmp(flag, "%%", 2) == 0)
		write(1, "%", 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_list	*format_list;
	t_list 	**pr;
	int		printed_char_count;

	printed_char_count = 0;
	va_start(ap, format);
	format_list = ft_splitflags((char *)format);
	pr = &format_list;
	while (format_list)
	{
		if (*(char *)format_list->content == '%')
			print_and_count(ap, (char *)format_list->content, &printed_char_count);
		else
		{
			write(1, format_list->content, ft_strlen((char *)format_list->content));
			printed_char_count += ft_strlen((char *)format_list->content);
		}
		format_list = format_list->next;
	}
	va_end(ap);
	ft_lstclear(pr, free);
	ft_lstclear(&format_list, free);
	return (printed_char_count);
}
