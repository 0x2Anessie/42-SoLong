/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:08:41 by acatusse          #+#    #+#             */
/*   Updated: 2023/11/09 16:00:53 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines_gnl(char *arg)
{
	int		fd;
	int		count_line;
	char	*line;

	count_line = 0;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		count_line++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count_line);
}

int	count_columns(char **map)
{
	int	count;

	count = 0;
	while (map[0] && map[0][count])
		count++;
	return (count);
}

int	count_lines(char **map)
{
	int	count;

	count = 0;
	while (map[count])
		count++;
	return (count);
}

void	map_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**change_newlines(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
			{
				map[i][j] = '\0';
			}
			j++;
		}
		i++;
	}
	return (map);
}

// void	print_map(char **map)
// {
// 	int	i;

// 	i = 0;
// 	while (map[i])
// 	{
// 		ft_printf("%s\n", map[i]);
// 		i++;
// 	}
// }

// void	test(char **map)
// {
// 	ft_printf("\nThe map:\n");
// 	print_map(map);
// 	ft_printf("\n");

// 	ft_printf("The map copy:\n");
// 	char **map_copy;
// 	map_copy = map_dup(map);
// 	print_map(map_copy);
// 	ft_printf("\n");

// 	int x = count_columns(map);
// 	ft_printf("Number of columns: %d\n", x);
// 	int y = count_lines(map);
// 	ft_printf("Number of lines: %d\n\n", y);

// 	t_position	start;
// 	start = find_p(map);
// 	ft_printf("P position:\n");
// 	ft_printf("X: %d, Y: %d\n\n", start.x, start.y);

// 	ft_printf("Check functions:\n");
// }