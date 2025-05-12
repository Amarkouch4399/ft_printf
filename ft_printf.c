/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:23:05 by ouamarko          #+#    #+#             */
/*   Updated: 2025/05/12 21:08:15 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(const char *format, int index, va_list arg)
{
	if (format[index] == '%' && format[index + 1] == 'd')
	{
		ft_putnbr(va_arg(arg, int));
		index++;
	}
	else if (format[index] == '%' && format[index + 1] == 'c')
	{
		ft_putchar(va_arg(arg, int));
		index++;
	}
	else if (format[index] == '%' && format[index + 1] == 's')
	{
		ft_putstr(va_arg(arg, char *));
		index++;
	}
	return (index);
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
/*
int	main()
{
	ft_printf("oussama %c %d %d %s", 'o', 42, 42, "amarkouch");
	
}
*/
