/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:36:01 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/11/10 12:49:05 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *format, ...);

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putunbr(unsigned int nb);
int	ft_putnbr(int nb);
int	ft_puthexnbr(unsigned int nb, char x);
int	ft_putaddr(void *ptr);

#endif