#include "so_long.h"

static int	map_init_set(char ***map, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		(*map)[i] = line;
		line = get_next_line(fd);
		i++;
	}
	(*map)[i] = 0;
	free(line);
	return (1);
}

char	**map_init(char *arg)
{
	int		fd;
	int		line_count;
	char	**map;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (0);
	line_count = count_lines_gnl(arg);
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
	{
		close(fd);
		free(map);
		return (NULL);
	}
	if (!map_init_set(&map, fd))
	{
		map_free(map);
		return (NULL);
	}
	close(fd);
	map = change_newlines(map);
	return (map);
}

char	**map_dup(char **map)
{
	int		i;
	int		lines;
	char	**map_copy;

	lines = count_lines(map);
	map_copy = malloc(sizeof(char *) * (lines + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	map_copy[i] = 0;
	return (map_copy);
}
