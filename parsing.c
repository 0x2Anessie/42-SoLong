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
	if (!check_map_shape(argv[1], map))
	{
		ft_printf("\033[31mError\nWrong map shape\n\033[0m");
		return (0);
	}
	else if (!check_elements(map))
	{
		ft_printf("\033[31mError\n\033[0m");
		ft_printf("\033[31mMissing or double elements\n\033[0m");
		return (0);
	}
	else if (!check_walls(map))
	{
		ft_printf("\033[31mError\n\033[0m");
		ft_printf("\033[31mSomething is wrong with your walls\n\033[0m");
		return (0);
	}
	else if (!check_path(map))
	{
		ft_printf("\033[31mError\n\033[0m");
		ft_printf("\033[31mThere is no valid path\n\033[0m");
		return (0);
	}
	return (1);
}
