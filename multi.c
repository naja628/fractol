#include "funs.h"

/* in .h */
//typedef struct
//{
//	int niter;
//	t_cpx c;
//	t_colorscheme sch;
//}	t_params;

void	ft_set_params(t_params *params, int niter, t_cpx c, double d)
{
	params->niter = niter;
	params->c = c;
	params->d = d;
	params->sch = ft_scheme_selector(0);
}

static t_cpx	t_expc(t_cpx z, double d)
{
	double	r;
	double	theta;
	t_cpx	w;

	r = pow(ft_modulus(z), d);
	theta = atan(z.im / z.re);
	w.re = r * cos(theta);
	w.im = r * sin(theta);
	return (w);
}
	
/* iterate z^d + c from z0 up to 'niter' times */
int	ft_iterate_zd_c(t_cpx c, t_cpx z0, void *data)
{
	t_params	*params;
	double		ratio_i;
	double		r;
	int			i;

	params = (t_params *) data;
	r = ft_modulus(c) / (d - 1) + 1;
	i = 0;
	if (2 - 0.0001 <= d && d <= 2 + 0.0001)
	{
		while (++i - 1 < params->niter && ft_modulus(z0) < r)
			z0 = ft_addc(ft_multc(z0, z0), c);
	}
	else 
	{
		while (++i - 1 < params->niter && ft_modulus(z0) < r)
			z0 = ft_addc(ft_expc(z0, d), c);
	}
	ratio_i = (double) (i - 1) / (params->niter);
	return (ft_gradient(params->sch.from, params->sch.to, ratio_i));
}

// to be given to ft_mapc
// z^d + c : mandelbrot -> map c, iterate from 0
// 		  : julia iterate from c 
int ft_multibrot(t_cpx c, void *data)
{
	return (ft_iterate_zd_c(c, ft_complex(0, 0), data));
}

int	ft_julia(t_cpx z0, void *data)
{
	t_params	*params;

	params = (t_params *) data;
	return (ft_iterate_zd_c(params->c, z0, data));
}
