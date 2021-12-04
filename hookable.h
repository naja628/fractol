#ifndef HOOKABLE_H
# define HOOKABLE_H

# include <stdio.h>
# include "ft_complex.h"
# include "funs.h"
# include "views.h"
# include "mlx.h"
# include "im_buffer.h"
# include "mapcomplex.h"

/* pointers to useful ressources 
 * that need to be passed around */
typedef struct s_state
{
	void		*win;
	t_im		*im;
	t_view		*active;
	t_view		*passive;
	t_cmap		*f;
	t_params	*params;
	int			needs_recompute;
}	t_state;

t_state	*ft_save_resources(void *win, t_im *im, int win_sz, t_cmap *f);
void	ft_quit(t_state *s);
void	ft_set_detail(t_state *s, int new_detail);
void	ft_rot_julia_const(t_state *s, double dtheta);
int		ft_print_julia_const(t_state *s);
void	ft_toggle_julia(t_state *s, int im_sz, int x, int y);
void	ft_next_color(t_state *s);

#endif
