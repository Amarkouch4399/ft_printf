/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:43:12 by ouamarko          #+#    #+#             */
/*   Updated: 2025/05/17 19:42:18 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_size(int nb)
{
	int	size;

	size = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		size = size * 10;
	}
	return (size);
}

static void	ft_putchar_nbr(int size, int nb, int temp)
{
	char	c;

	while (size != 0)
	{
		nb = temp / size;
		c = (nb % 10) + '0';
		write(1, &c, 1);
		size = size / 10;
	}
}

void	ft_putnbr(int nb)
{
	int	temp;
	int	size;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
	{
		write (1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	temp = nb;
	size = ft_size(nb);
	ft_putchar_nbr(size, nb, temp);
}
