/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:28:33 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/11/12 11:54:01 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static int	putptrnbr(uintptr_t nb)
{
	int	count;
	int	tmp;

	count = 0;
	if (nb > 15)
	{
		tmp = putptrnbr(nb / 16);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	if (nb % 16 < 10)
	{
		tmp = ft_putnbr(nb % 16);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	else
	{
		if (ft_putchar('a' + (nb % 16 - 10)) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_putaddr(void *ptr)
{
	uintptr_t	addr;
	int			count;
	int			tmp;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	addr = (uintptr_t)ptr;
	tmp = ft_putstr("0x");
	if (tmp == -1)
		return (-1);
	count += tmp;
	tmp = putptrnbr(addr);
	if (tmp == -1)
		return (-1);
	count += tmp;
	return (count);
}
