/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:29:10 by acatusse          #+#    #+#             */
/*   Updated: 2023/10/10 16:28:47 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_formats(va_list args, const char format)
{
	int	printables;

	printables = 0;
	if (format == 'c')
		printables += print_single_char(va_arg(args, int));
	else if (format == 's')
		printables += print_multiple_chars(va_arg(args, char *));
	else if (format == 'p')
		printables += print_pointer(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		printables += print_numbers(va_arg(args, int));
	else if (format == 'u')
		printables += print_unsigned_numbers(va_arg(args, unsigned int));
	else if (format == 'x')
		printables += print_hexa_min(va_arg(args, unsigned int));
	else if (format == 'X')
		printables += print_hexa_maj(va_arg(args, unsigned int));
	else if (format == '%')
		printables += print_single_char('%');
	return (printables);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			printables;
	va_list		args;

	i = 0;
	printables = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			printables += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			printables += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (printables);
}
/*
int	main(void)
{
	// char
	char c = 'N';
	char *s = "hihi";
	void *p = s;
	int	d = 5.7;
	int i = 42;
	int u = 13;
	unsigned int x = 0x25ab7;
	unsigned int X = 0x25AB7;
	char pc = '%';

	ft_printf("%c, %s, %p, %d, %i, %u, %x, %X, %%\n", c, s, p, d, i, u, x, X, pc);
	printf("%c, %s, %p, %d, %i, %u, %x, %X, %%", c, s, p, d, i, u, x, X, pc);
}*/
