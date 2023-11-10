/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:42:23 by acatusse          #+#    #+#             */
/*   Updated: 2023/11/10 16:04:48 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	search_ber(char	*arg)
{
	int	len;

	len = ft_strlen(arg);
	if (arg[len - 1] != 'r')
		return (0);
	else if (arg[len - 2] != 'e')
		return (0);
	else if (arg[len - 3] != 'b')
		return (0);
	else if (arg[len - 4] != '.')
		return (0);
	else
		return (1);
}

int	check_arg(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_printf("Invalid number of arguments !\n");
		return (0);
	}
	if (!search_ber(argv[1]))
	{
		ft_printf("Your file need to be a .ber type !\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("File not found !\n");
		return (0);
	}
	return (1);
}

int	ft_error(char **argv, char **map)
{
	if (!check_map_shape(argv[1], map) || !check_elements(map) \
		|| !check_walls(map) || !check_path(map))
	{
		ft_printf("\033[31mError\n\033[0m");
		return (0);
	}
	return (1);
}
