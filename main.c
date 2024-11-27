#include "so_long.h"

void	end_game(t_data	*data)
{
	data->mouv++;
	ft_printf("Nombre de mouvements : %d\n", data->mouv);
	ft_printf("\033[32m\tTu as fini le jeu en : %d coups\n\033[0m", data->mouv);
	close_window(data);
}

void	data_init(t_data *data)
{
	data->mouv = 0;
	data->width = 64;
	data->height = 64;
	data->remaining_c = count_collectibles(data->map);
	data->window = mlx_new_window(data->mlx, data->width * \
					count_columns(data->map), data->height * \
					count_lines(data->map), "so_long");
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!check_arg(argc, argv))
		return (0);
	data.map = map_init(argv[1]);
	if (!ft_error(argv, data.map))
	{
		map_free(data.map);
		return (0);
	}
	data.mlx = mlx_init();
	if (data.mlx == 0)
		exit(0);
	sprites_init(&data);
	data_init(&data);
	mlx_loop_hook(data.mlx, &display, &data);
	mlx_key_hook(data.window, &key_parsing, &data);
	mlx_hook(data.window, 17, 1L << 1, &close_window, &data);
	mlx_loop(data.mlx);
	map_free(data.map);
}
