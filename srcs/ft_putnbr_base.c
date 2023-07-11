/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:12:58 by rluiz             #+#    #+#             */
/*   Updated: 2023/06/07 17:17:59 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_ptr(unsigned long long nbr, char *base)
{
	if (nbr >= 16)
	{
		ft_print_ptr(nbr / 16, base);
		ft_print_ptr(nbr % 16, base);
	}
	else
		write(1, &base[nbr], 1);
}

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (nbr >= base_len)
		ft_putnbr_base(nbr / base_len, base);
	write(1, &base[nbr % base_len], 1);
}

void	ft_putnbr_base_long(unsigned long long nbr, char *base)
{
	unsigned long long	base_len;

	base_len = ft_strlen(base);
	if (nbr >= base_len)
		ft_putnbr_base(nbr / base_len, base);
	write(1, &base[nbr % base_len], 1);
}
