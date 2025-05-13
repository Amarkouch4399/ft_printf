/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:23:05 by ouamarko          #+#    #+#             */
/*   Updated: 2025/05/13 19:26:35 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hexa(unsigned long n)
{
	char *base = "0123456789abcdef";

	if (n >= 16)
		ft_putnbr_hexa(n / 16);
	ft_putchar(base[n % 16]);
}

void	ft_putchar_pointer(void *ptr)
{
	if (!ptr)
		return;
	ft_putstr("0x");
	ft_putnbr_hexa((unsigned long)ptr);
}

int	ft_check(const char *format, int index, va_list arg)
{
	if (format[index] == '%' && (format[index + 1] == 'd' || format[index + 1] == 'i'))
		ft_putnbr(va_arg(arg, int));
	else if (format[index] == '%' && format[index + 1] == 'c')
		ft_putchar(va_arg(arg, int));
	else if (format[index] == '%' && format[index + 1] == 's')
		ft_putstr(va_arg(arg, char *));
	else if (format[index] == '%' && format[index + 1] == 'p')
		ft_putchar_pointer(va_arg(arg, void *));
	return (index + 2);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	va_list		arg;

	va_start(arg, format);
	i = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_check(format, i, arg);
			i++;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (i);
}
int	main()
{
	ft_printf("oussama %c %p %d %s", 'o', "ouss", 42, "amarkouch");
	
}
