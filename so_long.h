#ifndef SO_LONG_H
# define SO_LONG_H

# define UP		115
# define DOWN	119
# define LEFT	97
# define RIGHT	100
# define ESC	65307

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

typedef struct s_position {
	int	x;
	int	y;
}	t_position;

typedef struct s_data {
	int		mouv;
	int		columns;
	int		lines;
	int		width;
	int		height;
	int		perso_x;
	int		perso_y;
	int		remaining_c;
	char	**map;
	void	*mlx;
	void	*window;
	void	*perso;
	void	*floor;
	void	*wall;
	void	*collectible;
	void	*exit;
}	t_data;

// Parsing functions
int			check_walls(char **map);
int			check_map_shape(char *arg, char **map);
int			check_path(char **map);
int			check_elements(char **map);

int			check_arg(int argc, char **argv);
int			ft_error(char **argv, char **map);

// Map parsing utils
int			check_wall_utils(char **map);
int			check_elements_utils(char **map);
int			check_double_elements(char **map);
int			check_collectible_elements(char **map);

// Path finding functions
t_position	find_p(char **map);
int			flood_fill(int x, int y, char **map);

// Map initialisation
char		**map_init(char *arg);
char		**map_dup(char **map);

// Game initialisation
void		*sprites_init(t_data *data);
int			close_window(t_data *data);
int			display(t_data *data);

// Key parsing
int			key_parsing(int key, t_data *data);
void		end_game(t_data	*data);

// Utils
int			count_lines_gnl(char *arg);
int			count_lines(char **map);
int			count_columns(char **map);
void		print_map(char **map);
char		**change_newlines(char **map);
void		map_free(char **map);
int			count_collectibles(char **map);

// Fonction perso de test
void		test(char **map);

#endif
