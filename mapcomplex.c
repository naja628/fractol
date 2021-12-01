#include "mapcomplex.h"

/** in .h **/
///* complex map type 
// * f is a fun for complex space
// * to rgb color space (as ints)
// * 'data' is used for extra parameters
// * to the function */
//typedef	struct	s_cmap
//{
//	void	*data;
//	int		(*f) (t_cpx, void *);
//} t_cmap;

void	ft_set_map(t_cmap *map, int (*f)(t_cpx, void *), void *data)
{
	map->data = data;
	map->f = f;
}

int	ft_apply_cmap(t_cmap *map, t_cpx z)
{
	return (map->f(z, map->data));
}

/* for a w by h image write the result of maping the
 * complex numbers in :
 * [topleft.re, topleft.re + w * pixsz] x [topleft.im, topleft.im + h * pixsz]
 * to colors using f */ 
void	ft_mapc(t_im *im, t_cpx topleft, double pixsz, t_cmap *f)
{
	int		pos;
	t_cpx	z;
	int		color;

	pos = 0;
	while (pos < im->width * im->height)
	{
		z = ft_complex((pos % im->width) * pixsz, -(pos / im->width) * pixsz);
		z = ft_addc(topleft, z);
		color = ft_apply_cmap(f, z);
		ft_pix_to_im(im, pos % im->width, pos / im->width, color);
		++pos;
	}
}	

#ifdef MAIN
#include "mlx.h"
#include <math.h>
#include <stdio.h>

/*
int	bound_modulus(t_cpx z, void *data)
{
	(void) data;
	////printf("%f maps to %x\n,", 1.0 - exp(-ft_modulus(z)), 
//			   (unsigned int) (0xff * (1.0 - exp(-ft_modulus(z)))));
//	return ((unsigned int) (0xffffff * 
//			(1.0 - exp(-ft_modulus(z)))));
	return ft_gradient(0xffffff, 0, 1.0 - exp(-ft_modulus(z)));
}
*/

typedef struct
{
	int niter;
	t_cpx c;
}	t_params;

#define CV 0x200010
#define DV 0xa080ff

/* iterate z^2 + c up to niter times */
int	ft_julia(t_cpx z, void *data)
{
	t_params	*params;
	double		r;

	params = (t_params *) data;
	r = ft_modulus(params->c) + 1;
	int i;
	for (i = 0; i < params->niter; ++i)
	{
		z = ft_addc(ft_multc(z, z), params->c);
		if (ft_modulus(z) > r)
			break ;
	}
	return (ft_gradient(CV, DV, (double) i / (params->niter)));
}

int main()
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 1000, 750, "bouh");
	t_im *im = ft_init_im(mlx, 1000, 750);
	//t_params params = {300, ft_complex(-0.122, 0.744)};
	t_params params = {300, ft_complex(-0.8, 0.156)};
	t_cmap *f = ft_new_map(ft_julia, (void *) &params);
	ft_mapc(im, ft_complex(-2, 1.5), 250, f);
	mlx_put_image_to_window(mlx, win, im->im, 0, 0);

	mlx_loop(mlx);
}

#endif
