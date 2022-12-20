NAME = fdf
SRCS =	main.c $(SRCS_FOLDER)
		
SRCS_FOLDER =	src/colors.c \
				src/err_keys_exit.c \
				src/general_used_utils.c \
				src/draw/form_image_in_window.c \
				src/draw/my_line_draw.c \
				src/draw/my_pixel_put.c \
				src/map/check_grid_size.c \
				src/map/my_atoi_hex.c \
				src/map/read_map_utils.c \
				src/map/read_map.c \
				src/transformation/apply_transformation_isometric.c \
				src/transformation/apply_transformation_to_line.c \
				src/transformation/identity_combine.c \
				src/transformation/transformation_utils.c \
				src/transformation/translate_scale_rotate.c \
				src/work_with_lines/form_lines_from_grid.c \
				src/work_with_lines/grid_get_color_cell_point.c \
				src/work_with_lines/transform_lines.c \

OBJ = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror -g

LIBMLX_FILE = libmlx.dylib
LIBMLX_HEADER = mlx
LIBFT = libft.a
LIBFT_HEADER = libft
HEADER = includes
CC = clang

all: $(NAME)

$(NAME): $(OBJ) $(LIBMLX_FILE) $(LIBFT)
	$(CC) $(OBJ) $(LIBMLX_FILE) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c -o $@ $< -I $(HEADER) -I $(LIBMLX_HEADER) -I $(LIBFT_HEADER)

$(LIBFT):
	$(MAKE) -C libft
	cp libft/libft.a .

$(LIBMLX_FILE):
	$(MAKE) -C mlx
	cp mlx/libmlx.dylib .

clean:
	rm -f $(OBJ) $(LIBMLX_FILE) $(LIBFT)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
