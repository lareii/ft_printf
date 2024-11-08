/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:36:01 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/11/08 15:41:00 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

int		ft_printf(const char *format, ...);

size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);
size_t	ft_putunbr(unsigned int nb);
size_t	ft_putnbr(int nb);
size_t	ft_puthex(unsigned int nb, char x);
size_t	ft_putaddr(void *ptr);

#endif