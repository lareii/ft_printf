/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:25:13 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/11/11 18:26:22 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	count;
	int	tmp;

	count = 0;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		nb = -nb;
		count++;
	}
	if (nb > 9)
		count += ft_putnbr(nb / 10);
	tmp = ft_putchar('0' + nb % 10);
	if (tmp == -1)
		return (-1);
	count += tmp;
	return (count);
}

int	ft_putunbr(unsigned int nb)
{
	int	count;
	int	tmp;

	count = 0;
	if (nb > 9)
		count += ft_putunbr(nb / 10);
	tmp = ft_putchar('0' + nb % 10);
	if (tmp == -1)
		return (-1);
	count += tmp;
	return (count);
}

int	ft_puthexnbr(unsigned int nb, char x)
{
	int	count;
	int	tmp;

	count = 0;
	if (nb > 15)
		count += ft_puthexnbr(nb / 16, x);
	if (nb % 16 < 10)
	{
		tmp = ft_putnbr(nb % 16);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	else
	{
		tmp = ft_putchar((x - 23) + (nb % 16 - 10));
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	return (count);
}
