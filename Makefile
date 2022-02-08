# at 19
# MLX_DIR = '/usr/local'
#
# on my pc
MLX_DIR = /home/nat/apkg/mlx

# mac
# OS=MAC
# LIB=-L${MLX_DIR} -lmlx -lm -framework AppKit -framework OpenGL
#
# linux
OS=LINUX
LIB=-L${MLX_DIR} -lmlx -lm -lXext -lX11

SRC= console_args.c ft_complex.c funs.c hookable1.c hookable2.c hooks.c \
	 im_buffer.c main.c mapcomplex.c select_color.c utils.c views.c
OBJ=${SRC:.c=.o}
CFLAGS=-Wall -Wextra -Werror
CC=gcc
INC=-I${MLX_DIR}
NAME=fractol

%.o:%.c
	${CC} -c -D ${OS} ${CFLAGS} ${INC} $<

${NAME}: ${OBJ}
	${CC} ${CFLAGS} -o $@ $^ ${INC} ${LIB}
	
all: ${NAME}
	@#empty

bonus: all
	@#empty

clean: 
	rm -rf ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
	@#empty

.PHONY: all re fclean clean bonus all
