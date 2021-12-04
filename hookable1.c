#include "hookable.h"

///* in .h */
///* pointers to useful ressources 
// * that need to be passed around
// * note : params is redundant 
// * (but practical) as it is 
// * already a member of f */
//
//typedef struct s_state
//{
//	void		*win;
//	t_im		*im;
//	t_view		*active;
//	t_view		*passive;
//	t_cmap		*f;
//	t_params	*params;
//}	t_state;

t_state	*ft_save_resources(void *win, t_im *im, int win_sz, t_cmap *f)
{
	t_state	*s;

	s = malloc(sizeof(t_state));
	if (!s)
		return (NULL);
	s->passive = malloc(sizeof(t_view));
	s->active = malloc(sizeof(t_view));
	if (!s->passive | !s->active)
		return (NULL);
	s->win = win;
	s->im = im;
	ft_set_view(s->passive, ft_complex(-2, 2), 4.0 / win_sz);
	ft_set_view(s->active, ft_complex(-2, 2), 4.0 / win_sz);
	s->f = f;
	s->params = f->data;
	s->needs_recompute = 1;
	return (s);
}

void	ft_quit(t_state *s)
{
	mlx_destroy_window(s->im->mlx, s->win);
	mlx_destroy_image(s->im->mlx, s->im->im);
	if (s)
	{
		free(s->passive);
		free(s->active);
	}
	free(s);
	exit(0);
}

// change the params in some way

void	ft_set_detail(t_state *s, int new_detail)
{
	s->params->niter = new_detail;
}

void	ft_rot_julia_const(t_state *s, double dtheta)
{
	t_cpx	zrot;

	zrot = ft_rot(dtheta);
	s->params->c = ft_multc(s->params->c, zrot);
}

/* sends an int for bad-norminetty reasons 
 * (flow control that should not be here) */
int	ft_print_julia_const(t_state *s)
{
	printf("%.3f + i%.3f\n", s->params->c.re, s->params->c.im);
	return (0);
}
