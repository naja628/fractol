#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "ft_complex.h"
#include "im_buffer.h"
#include "mapcomplex.h"
#include "funs.h"
#include "hooks.h"
#include "console_args.h"
#include <stdio.h>

// possible errors / warnings (ordered by severity)
#define OK 0
#define HELP 1
#define EXTRA_ARGS 2
#define WRONG_ARGS 3
#define FATAL 4

static void	print_helpbox(void)
{
	printf("** HELPBOX **\n"
		"## Running the program \n"
		"run with one of :\n"
		"  * ./fract-ol : same as ./fract-ol -mandelbrot\n"
		"  * ./fract-ol -mandelbrot : to display the madelbrot set\n"
		"  * ./fract-ol -julia x y : to dispaly the julia set of the "
		"function z -> z^2 + c where c = x/1000 + i.y/1000\n"
		"  * ./fract-ol -multibrot d : with d > 1000 to display the "
		"multibrot set for z -> z^(d/1000) + c \n"
		"  * ./fract-ol -help : to print this help box \n"
		"## Using the program \n"
		"  * esc : exit\n"
		"  * mouse scroll : zoom\n"
		"  * arrows : move around\n"
		"  * left click : redraw with more detail\n"
		"  * space : change color scheme\n"
		"#### Julia only :\n"
		"  * j/k : rotate the constant anti/clockwise by a *tiny* angle\n"
		"  * p : print the constant to stdout (eg so you can input it later)\n"
		"  * right click : go to previous view of the mandelbrot set (or "
		"multibrot). This loses the Julia fractal view. (1)\n"
		"#### Multi/Mandelbrot only : \n"
		"  * right click : display julia fractal for z^2 + c (multi : z^d + "
		"c) where c is where you clicked (1)\n");
}

static void	ft_parse_args(t_state *s, int ac, char **av, int *status)
{
	t_cpx	c;
	int		e;

	if (ac > 2 && !ft_strncmp(av[1], "-mandelbrot", 12))
		*status = EXTRA_ARGS;
	if (ac == 1 || !ft_strncmp(av[1], "-mandelbrot", 12))
		s->f->f = ft_mandelbrot;
	else if (!ft_strncmp(av[1], "-julia", 7))
	{
		s->f->f = ft_julia;
		if (ac >= 4)
			c = ft_complex(ft_xatoi(av[2], &e), ft_xatoi(av[3], &e));
		if (ac < 4 || e == -1)
			*status = WRONG_ARGS;
		else
			s->params->c = c;
		if (*status == OK && ac > 4)
			*status = EXTRA_ARGS;
	}
	else if (!ft_strncmp(av[1], "-help", 6))
		*status = HELP;
	else
		*status = WRONG_ARGS;
}

static void	ft_message(int status)
{
	if (status == EXTRA_ARGS)
		ft_puterr("Warning : some extraneous arguments were ignored\n");
	if (status == WRONG_ARGS)
		ft_puterr("Error : wrong commandline arguments\n");
	if (status == FATAL)
		ft_puterr("Error : fatal (maybe you ran out of RAM?)\n");
	if (status == WRONG_ARGS || status == HELP)
		print_helpbox();
}

// fill s with placeholder value then call parse input 
// to init everything the way we want
static void	ft_do_the_thing(int ac, char **av, void *mlx, void *win)
{
	t_im		im;
	t_params	params;
	t_cmap		f;
	t_state		*s;
	int			status;

	status = OK;
	ft_init_im(mlx, &im, WIN_SZ, WIN_SZ);
	ft_set_params(&params, DEF_DETAIL, ft_complex(0, 0));
	ft_set_map(&f, NULL, &params);
	s = ft_save_resources(win, &im, WIN_SZ, &f);
	ft_parse_args(s, ac, av, &status);
	if (!mlx || !win || !im.im || !s)
		status = FATAL;
	ft_message(status);
	if (status == WRONG_ARGS || status == FATAL || status == HELP)
		ft_quit(s);
	mlx_key_hook(win, ft_kbd_hook, s);
	mlx_mouse_hook(win, ft_ms_hook, s);
	mlx_loop_hook(mlx, ft_redraw_as_needed, s);
	mlx_loop(mlx);
}

int	main(int ac, char **av)
{
	void		*mlx;
	void		*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_SZ, WIN_SZ, "fractal");
	ft_do_the_thing(ac, av, mlx, win);
	return (0);
}
