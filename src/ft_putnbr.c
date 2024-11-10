/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:25:13 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/11/10 12:48:08 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		count = ft_putstr("-2147483648");
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
			count++;
		}
		if (nb > 9)
			count += ft_putnbr(nb / 10);
		count += ft_putchar('0' + nb % 10);
	}
	return (count);
}

int	ft_putunbr(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
		count += ft_putunbr(nb / 10);
	count += ft_putchar('0' + nb % 10);
	return (count);
}

int	ft_puthexnbr(unsigned int nb, char x)
{
	int	count;

	count = 0;
	if (nb > 15)
		count += ft_puthexnbr(nb / 16, x);
	if (nb % 16 < 10)
		count += ft_putnbr(nb % 16);
	else
		count += ft_putchar((x - 23) + (nb % 16 - 10));
	return (count);
}
