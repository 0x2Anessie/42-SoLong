/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:51:14 by acatusse          #+#    #+#             */
/*   Updated: 2023/10/10 16:28:59 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_unsigned_numbers(unsigned int nb)
{
	int	printables;

	printables = 0;
	if (nb > 9)
	{
		printables += print_numbers(nb / 10);
		printables += print_numbers(nb % 10);
	}
	else
		printables += print_single_char(nb + '0');
	return (printables);
}

int	print_hexa_min(unsigned long long nb)
{
	char	*base_hex;
	int		printables;

	printables = 0;
	base_hex = "0123456789abcdef";
	if (nb >= 16)
		printables += print_hexa_min(nb / 16);
	printables += write(1, &base_hex[nb % 16], 1);
	return (printables);
}

int	print_hexa_maj(unsigned int nb)
{
	char	*base_hex;
	long	printables;

	printables = 0;
	base_hex = "0123456789ABCDEF";
	if (nb >= 16)
		printables += print_hexa_maj(nb / 16);
	printables += write(1, &base_hex[nb % 16], 1);
	return (printables);
}
