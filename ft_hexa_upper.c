/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_upper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:03:33 by ouamarko          #+#    #+#             */
/*   Updated: 2025/05/13 21:17:48 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa_upper(unsigned long n)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n >= 16)
		ft_hexa_upper(n / 16);
	ft_putchar(base[n % 16]);
}
