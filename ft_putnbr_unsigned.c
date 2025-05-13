/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:39:15 by ouamarko          #+#    #+#             */
/*   Updated: 2025/05/13 21:12:46 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_size(unsigned int nb)
{
	unsigned int	size;

	size = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

void	ft_putchar_nbr(unsigned int size, unsigned int nb)
{
	char			c;
	unsigned int	div;

	div = 1;
	while (--size > 0)
		div *= 10;
	while (div > 0)
	{
		c = (nb / div) + '0';
		write(1, &c, 1);
		nb %= div;
		div /= 10;
	}
}

void	ft_putnbr_unsigned(unsigned int nb)
{
	unsigned int	size;

	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	size = ft_size(nb);
	ft_putchar_nbr(size, nb);
}
