/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:26:00 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/11/11 14:46:33 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;
	int	tmp;

	count = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
	{
		tmp = ft_putchar(*s++);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	return (count);
}
