/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:28:33 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/11/10 12:48:23 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static int	putptrnbr(uintptr_t nb)
{
	int	count;

	count = 0;
	if (nb > 15)
		count += putptrnbr(nb / 16);
	if (nb % 16 < 10)
		count += ft_putnbr(nb % 16);
	else
		count += ft_putchar('a' + (nb % 16 - 10));
	return (count);
}

int	ft_putaddr(void *ptr)
{
	uintptr_t	addr;
	int			count;

	count = 0;
	addr = (uintptr_t)ptr;
	count += ft_putstr("0x");
	count += putptrnbr(addr);
	return (count);
}
