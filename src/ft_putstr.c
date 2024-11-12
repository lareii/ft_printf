/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:26:00 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/11/12 11:40:15 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
		s = "(null)";
	while (s[count])
		count++;
	return (write(1, s, count));
}
