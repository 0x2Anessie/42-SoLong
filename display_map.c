#include "so_long.h"

void	*sprites_init(t_data *data)
{
	data->perso = mlx_xpm_file_to_image(data->mlx, "sprites/perso.xpm", \
			&data->width, &data->height);
	if (!data->perso)
		return (0);
	data->floor = mlx_xpm_file_to_image(data->mlx, "sprites/floor.xpm", \
			&data->width, &data->height);
	if (!data->floor)
		return (0);
	data->wall = mlx_xpm_file_to_image(data->mlx, "sprites/wall.xpm", \
			&data->width, &data->height);
	if (!data->wall)
		return (0);
	data->collectible = mlx_xpm_file_to_image(data->mlx, \
				"sprites/collectible.xpm", &data->width, \
				&data->height);
	if (!data->collectible)
		return (0);
	data->exit = mlx_xpm_file_to_image(data->mlx, "sprites/exit.xpm", \
			&data->width, &data->height);
	if (!data->exit)
		return (0);
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	map_free(data->map);
	mlx_destroy_image(data->mlx, data->perso);
	mlx_destroy_image(data->mlx, data->floor);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->collectible);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void	display_utils(t_data *data, int i, int j)
{			
	if (data->map[i][j] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->perso, \
		data->height * j, data->width * i);
		data->perso_x = j;
		data->perso_y = i;
	}
	else if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->window, data->wall, \
		data->height * j, data->width * i);
	else if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->window, data->floor, \
		data->height * j, data->width * i);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->window, data->exit, \
		data->height * j, data->width * i);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->window, data->collectible, \
		data->height * j, data->width * i);
}

void	display_mouv_count(t_data *data)
{
	char	*str;

	str = ft_itoa(data->mouv);
	mlx_string_put(data->mlx, data->window, 10, 32, 0x00000000, "NB = ");
	mlx_string_put(data->mlx, data->window, 40, 32, 0x00000000, str);
	free(str);
}

int	display(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' || data->map[i][j] == '1' ||
					data->map[i][j] == '0' || data->map[i][j] == 'E' ||
					data->map[i][j] == 'C')
				display_utils(data, i, j);
			j++;
		}
		i++;
	}
	display_mouv_count(data);
	return (0);
}
