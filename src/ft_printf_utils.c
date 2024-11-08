/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:22:08 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/11/08 16:14:31 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

size_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t	ft_putstr(char *s)
{
	size_t	count;

	count = 0;
	if (!s)
	{
		ft_putstr("(null)");
		count = 6;
	}
	while (s && *s)
	{
		ft_putchar(*s++);
		count++;
	}
	return (count);
}

size_t	ft_putunbr(unsigned int nb)
{
	size_t	count;

	count = 0;
	if (nb > 9)
		count += ft_putunbr(nb / 10);
	count += ft_putchar('0' + nb % 10);
	return (count);
}

size_t	ft_putnbr(int nb)
{
	size_t	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
	}
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

size_t	ft_puthex(unsigned int nb, char x)
{
	size_t	count;

	count = 0;
	if (nb > 15)
		count += ft_puthex(nb / 16, x);
	if (nb % 16 < 10)
		count += ft_putnbr(nb % 16);
	else
		count += ft_putchar((x - 23) + (nb % 16 - 10));
	return (count);
}

size_t	ft_puthex_long(uintptr_t nb, char x)
{
	size_t	count;

	count = 0;
	if (nb > 15)
		count += ft_puthex_long(nb / 16, x);
	if (nb % 16 < 10)
		count += ft_putnbr(nb % 16);
	else
		count += ft_putchar((x - 23) + (nb % 16 - 10));
	return (count);
}

size_t	ft_putaddr(void *ptr)
{
	uintptr_t	addr;
	size_t		count;

	count = 0;
	addr = (uintptr_t)ptr;
	count += ft_putstr("0x");
	count += ft_puthex_long(addr, 'x');
	return (count);
}
