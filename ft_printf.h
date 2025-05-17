/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:38:09 by ouamarko          #+#    #+#             */
/*   Updated: 2025/05/17 16:26:56 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr_unsigned(unsigned int nb);
void	ft_putnbr_hexa(unsigned long n);
void	ft_putchar_pointer(void *ptr);
void	ft_putnbr_hexa(unsigned long n);
void	ft_hexa_upper(unsigned long n);

#endif
