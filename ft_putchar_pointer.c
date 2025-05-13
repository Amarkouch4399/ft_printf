/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:19:45 by ouamarko          #+#    #+#             */
/*   Updated: 2025/05/13 21:15:02 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_pointer(void *ptr)
{
	if (!ptr)
		return ;
	write(1, "0x", 2);
	ft_putnbr_hexa((unsigned long)ptr);
}
