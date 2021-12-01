SRC = ft_complex.c funs.c hookable.c hooks.c im_buffer.c main.c mapcomplex.c select_color.c utils.c views.c console_args.c

all: ${SRC}
	gcc -Wall -Wextra ${SRC} -o fract-ol -I ~/apkg/mlx -L ~/apkg/mlx -lmlx -lXext -lX11 -lm

