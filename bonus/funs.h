#ifndef FUNS_H
# define FUNS_H

# include "select_color.h"
# include "utils.h"
# include "ft_complex.h"

typedef struct s_params
{
	int				niter;
	t_cpx			c;
	t_colorscheme	sch;
}	t_params;

void	ft_set_params(t_params *params, int niter, t_cpx c);
/* iterate z^2 + c from z0 up to 'niter' (in data) times
 * return color "proportional" to the numbers of iters before divergence */
int		ft_iterate_z2_c(t_cpx c, t_cpx z0, void *data);
// to be given to ft_mapc
// z2 + c : mandelbrot -> map c, iterate from 0
// 		  : julia iterate from c 
int		ft_julia(t_cpx z0, void *data);
int		ft_mandelbrot(t_cpx c, void *data);

#endif
