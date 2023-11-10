NAME =	so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L./minilibx-linux -lmlx -lX11 -lXext -lm
RM = rm -rf

SRCS = parsing.c pars_map.c pars_map_utils.c utils.c main.c map_init.c flood_fill.c \
		display_map.c key_parsing.c

OBJS = $(SRCS:.c=.o)

TOTAL_FILES = $(words $(SRCS))

all:			$(NAME)
				@clear
				@echo "  _________         ____                           ";
				@echo " /   _____/ ____   |    |    ____   ____    _____  ";
				@echo " \_____  \ /    \  |    |   /    \ /    \  /     \ ";
				@echo " /        \   |  | |    |__|   |  |   |  \/  /   / ";
				@echo "/_______  /\____/  |_______ \____/|___|  /\___  /  ";
				@echo "        \/                 \/          \//_____/   ";

$(NAME):		$(OBJS)
				make -C libft/
				make -C minilibx-linux/
				$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(MLX_FLAGS) libft/libft.a minilibx-linux/libmlx.a

.c.o:
	@CURRENT_COUNT=$$(ls $(OBJS) 2>/dev/null | wc -l); \
	printf "\e[32mCompiling so_long... [$$CURRENT_COUNT/$(TOTAL_FILES)]\e[0m\r"; \
	$(CC) $(CFLAGS) -c $< -o $@

clean:			
				make clean -C libft/
				make clean -C minilibx-linux/
				$(RM) $(OBJS)
				@clear
				@echo "        /\                __              __                         ";
				@echo "  ____  )/ ____   _______/  |_      ____ |  |   ____  _____    ____   ";
				@echo "/  ___\  /  __ \ /  ___/\   __\   /  ___\|  | /  __ \ \__  \  /    \  ";
				@echo "\  \___  \  ___/ \___ \  |  |     \  \___|  |_\  ___/ / __  \|   |  \ ";
				@echo " \____ >  \____ >_____ > |__|      \____ >____/\____> ____  / ___|  / ";
				@echo "                                                          \/      \/  ";


fclean: 		clean
				$(RM) $(NAME) libft/libft.a libmlx_Linux.a
				@clear
				@echo "        /\                __        _____       __                         ";
				@echo "  ____  )/ ____   _______/  |_    _/ ____\____ |  |   ____  _____    ____   ";
				@echo "/  ___\  /  __ \ /  ___/\   __\   \  __\/  ___\|  | /  __ \ \__  \  /    \  ";
				@echo "\  \___  \  ___/ \___ \  |  |      |  | \  \___|  |_\  ___/  / __ \|   |  \ ";
				@echo " \____ >  \____> _____ > |__|      |__|  \____ >____/\____ > ____  /___|  / ";
				@echo "                                                                 \/     \/  ";

re: 			fclean all

.PHONY:			all clean fclean re