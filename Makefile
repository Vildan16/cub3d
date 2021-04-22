# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/22 14:58:40 by ameta             #+#    #+#              #
#    Updated: 2021/04/22 15:10:21 by ameta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
HEADER_FILE = cub.h
INC_DIR = ./includes/
SRC_DIR = ./src/
LIBFT_DIR = ./libft/
LIBFT_LIB = libft.a
MLX_DIR = ./mlx/
MLX_LIB = libmlx.dylib
CFLAGS = -Wall -Wextra -Werror
SRC_FILES =			$(SRC_DIR)main.c \
					$(SRC_DIR)ft_bmp_save.c \
					$(SRC_DIR)ft_check_map.c \
					$(SRC_DIR)ft_game_init.c \
					$(SRC_DIR)ft_game_start.c \
					$(SRC_DIR)ft_get_info.c \
					$(SRC_DIR)ft_get_map.c \
					$(SRC_DIR)ft_get_map2.c \
					$(SRC_DIR)ft_parse_map.c \
					$(SRC_DIR)ft_player_move.c \
					$(SRC_DIR)ft_player_move2.c \
					$(SRC_DIR)ft_raycasting.c \
					$(SRC_DIR)ft_raycasting2.c \
					$(SRC_DIR)ft_set_sprite.c \
					$(SRC_DIR)ft_set_texture.c \
					$(SRC_DIR)ft_sort_sprites.c \
					$(SRC_DIR)ft_sprite_draw.c

all: $(NAME)

$(NAME): $(SRC_FILES) $(INC_DIR)$(HEADER_FILE)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	mv $(LIBFT_DIR)$(LIBFT_LIB) .
	mv $(MLX_DIR)$(MLX_LIB) .
	$(CC) $(CFLAGS) -O3 -L. -lft -lmlx $(SRC_FILES) -o $(NAME)

clean:
	rm -f $(LIBFT_LIB) $(MLX_LIB)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
