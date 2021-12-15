MLX_DIR = '/home/nat/apkg/mlx'
SRC= console_args.c ft_complex.c funs.c hookable1.c hookable2.c hooks.c \
	 im_buffer.c main.c mapcomplex.c select_color.c utils.c views.c
OBJ=${SRC:.c=.o}
CFLAGS=-Wall -Wextra -Werror
CC=gcc
INC=-I${MLX_DIR}
LIB=-L${MLX_DIR} -lmlx -lXext -lX11 -lm
NAME=fractol

%.o:%.c
	${CC} -c ${CFLAGS} ${INC} $<

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
