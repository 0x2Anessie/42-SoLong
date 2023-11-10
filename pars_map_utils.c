/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:09:14 by acatusse          #+#    #+#             */
/*   Updated: 2023/11/08 12:21:42 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall_utils(char **map)
{
	int	i;
	int	first;
	int	last_line;
	int	last_column;

	i = 1;
	last_line = count_lines(map) - 1;
	first = 0;
	last_column = ft_strlen(map[i]) - 1;
	while (i < last_line)
	{
		if (map[i][first] != '1')
			return (0);
		else if (map[i][last_column] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_elements_utils(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && \
				map[i][j] != 'P' && map[i][j] != 'C' && \
				map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_double_elements(char **map)
{
	int	i;
	int	j;
	int	count_p;
	int	count_e;

	i = -1;
	count_p = 0;
	count_e = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				count_p++;
			else if (map[i][j] == 'E')
				count_e++;
		}
	}
	if (count_p == 0 || count_e == 0)
		return (0);
	if (count_p > 1 || count_e > 1)
		return (0);
	return (1);
}

int	check_collectible_elements(char **map)
{
	int	i;
	int	j;
	int	count_c;

	i = 0;
	j = 0;
	count_c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count_c++;
			j++;
		}
		i++;
	}
	if (count_c < 1)
		return (0);
	return (1);
}

int	count_collectibles(char **map)
{
	int	i;
	int	j;
	int	count_c;

	i = 0;
	j = 0;
	count_c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count_c++;
			j++;
		}
		i++;
	}
	return (count_c);
}
