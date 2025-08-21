# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 15:39:28 by merazafi          #+#    #+#              #
#    Updated: 2025/08/09 19:00:52 by merazafi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
BONUS = fdf_bonus

SRC = ./mandatory/fdf.c\
	./mandatory/event.c\
	./mandatory/fdf_utils.c\
	./mandatory/bresenham.c\
	./mandatory/verif_map.c\
	./mandatory/init_struct.c\
	./mandatory/define_color.c\
	./mandatory/rendering_map.c\
	./mandatory/define_color_func.c\
	./mandatory/./parse/parse_map.c\
	./mandatory/./parse/free_parse.c\
	./mandatory/./parse/parsing_utils.c\
	./mandatory/./parse/parsing_utils_pt2.c\
	./mandatory/./parse/parsing_utils_pt3.c\
	./mandatory/./get_next/get_next_line.c\
	./mandatory/./get_next/get_next_line_utils.c\

SRC_BONUS = ./bonus/fdf_bonus.c\
	./bonus/move_bonus.c\
	./bonus/event_bonus.c\
	./bonus/fdf_utils_bonus.c\
	./bonus/bresenham_bonus.c\
	./bonus/verif_map_bonus.c\
	./bonus/event_without_iso.c\
	./bonus/init_struct_bonus.c\
	./bonus/define_color_bonus.c\
	./bonus/define_color_func_bonus.c\
	./bonus/rendering_map_bonus.c\
	./bonus/parse/parse_map_bonus.c\
	./bonus/parse/free_parse_bonus.c\
	./bonus/parse/parsing_utils_bonus.c\
	./bonus/parse/parsing_utils_pt2_bonus.c\
	./bonus/parse/parsing_utils_pt3_bonus.c\
	./bonus/get_next/get_next_line_bonus.c\
	./bonus/get_next/get_next_line_utils_bonus.c\

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CC = gcc -g
FLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lm -lmlx -lXext -lX11
INCLUDES = -I. -I$(MLX_DIR) -I/usr/include

all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJ) $(MLX_FLAGS) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJ_BONUS) $(MLX)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJ_BONUS) $(MLX_FLAGS) -o $(BONUS)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -O3 -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR) all

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus