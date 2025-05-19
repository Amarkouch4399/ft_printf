/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:23:05 by ouamarko          #+#    #+#             */
/*   Updated: 2025/05/17 19:52:04 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(const char *format, int index, va_list arg)
{
	int	count;

	count = 0;
	if (format[index + 1] == 'd' || format[index + 1] == 'i')
		count = count + ft_putnbr(va_arg(arg, int));
	else if (format[index] == '%' && format[index + 1] == 'c')
		count = count + ft_putchar(va_arg(arg, int));
	else if (format[index] == '%' && format[index + 1] == 's')
		count = count + ft_putstr(va_arg(arg, char *));
	else if (format[index] == '%' && format[index + 1] == 'p')
		count = count + ft_putchar_pointer(va_arg(arg, void *));
	else if (format[index] == '%' && format[index + 1] == '%')
		count = count + ft_putchar('%');
	else if (format[index] == '%' && format[index + 1] == 'u')
		count = count + ft_putnbr_unsigned(va_arg(arg, unsigned int));
	else if (format[index] == '%' && format[index + 1] == 'x')
		count = count + ft_putnbr_hexa(va_arg(arg, unsigned int));
	else if (format[index] == '%' && format[index + 1] == 'X')
		count = count + ft_hexa_upper(va_arg(arg, unsigned int));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	int			count;
	va_list		arg;

	va_start(arg, format);
	i = 0;
	count = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count = count + ft_check(format, i, arg);
			i = i + 2;
		}
		else
		{
			count = count + ft_putchar(format[i]);
			i++;
		}
	}
	va_end(arg);
	return (count);
}
/*
#include <stdio.h>
int	main()
{
	ft_printf("oussama %x %s %p %d %x", 1234,"", NULL, 12354, 255);
	printf("\n");
	printf("oussama %x %s %p %d %x", 1234,"", NULL, 12354, 255);
	
}
*/
