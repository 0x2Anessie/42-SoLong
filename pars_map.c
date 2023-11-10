/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:42:04 by acatusse          #+#    #+#             */
/*   Updated: 2023/11/10 15:26:21 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_shape(char *arg, char **map)
{
	int	x;
	int	y;
	int	i;

	x = count_columns(map);
	y = count_lines_gnl(arg);
	if (x < 4 || y < 3)
		return (0);
	else if (x == y)
		return (0);
	i = 0;
	while (map[i] && map[i + 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(char **map)
{
	int	i;
	int	last_line;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	last_line = count_lines(map) - 1;
	i = 0;
	while (map[last_line][i])
	{
		if (map[last_line][i] != '1')
			return (0);
		i++;
	}
	if (!check_wall_utils(map))
		return (0);
	return (1);
}

int	check_elements(char **map)
{
	if (!check_elements_utils(map))
		return (0);
	if (!check_double_elements(map))
		return (0);
	if (!check_collectible_elements(map))
		return (0);
	return (1);
}

int	check_path(char **map)
{
	char		**map_copy;
	t_position	start;

	map_copy = map_dup(map);
	start = find_p(map_copy);
	if (!flood_fill(start.x, start.y, map_copy))
	{
		map_free(map_copy);
		return (0);
	}
	map_free(map_copy);
	return (1);
}
