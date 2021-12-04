#include "hooks.h"

/* in hookable.h */
///* pointers to useful ressources 
// * that need to be passed around */
//typedef struct s_state
//{
//	void		*win;
//	t_im		*im;
//	t_view		*active;
//	t_view		*passive;
//	t_cmap		*f;
//	t_params	*params;
//	int			needs_recompute;
//}	t_state;

static void	ft_redraw(void *win, t_im *im, t_view *v, t_cmap *f)
{
	ft_mapc(im, v->topleft, v->pixsz, f);
	mlx_put_image_to_window(im->mlx, win, im->im, 0, 0);
}

int	ft_kbd_hook(int keycode, void *state)
{
	t_state	*s;

	s = (t_state *) state;
	if (keycode == ESC)
		ft_quit(s);
	if (keycode == UP)
		ft_move_around(s->active, 0, -MV_SPEED);
	if (keycode == DOWN)
		ft_move_around(s->active, 0, MV_SPEED);
	if (keycode == LEFT)
		ft_move_around(s->active, -MV_SPEED, 0);
	if (keycode == RIGHT)
		ft_move_around(s->active, MV_SPEED, 0);
	if (keycode == 'j')
		ft_rot_julia_const(s, -DTHETA);
	if (keycode == 'k')
		ft_rot_julia_const(s, DTHETA);
	if (keycode == SPC)
		ft_next_color(s);
	if (keycode == 'p')
		return (ft_print_julia_const(s));
	ft_set_detail(s, DEF_DETAIL);
	s->needs_recompute = 1;
	return (0);
}

int	ft_ms_hook(int button, int x, int y, void *state)
{
	t_state	*s;

	s = (t_state *) state;
	if (button == MS_LEFT)
		ft_set_detail(s, s->params->niter + DETAIL_INCR);
	else
		ft_set_detail(s, DEF_DETAIL);
	if (button == MS_RIGHT)
		ft_toggle_julia(s, WIN_SZ, x, y);
	if (button == SCROLL_UP)
		ft_zoom_view(s->active, ZOOM, x, y);
	else if (button == SCROLL_DOWN)
		ft_zoom_view(s->active, 1 / ZOOM, x, y);
	s->needs_recompute = 1;
	return (0);
}

/* The point of is (eg as opposed to having 
 * 'ft_redraw' at the end of the others hooks)
 * is that, when user preses many buttons quickly 
 * (eg fast mouse scroll) we do only 1 recompute 
 * for every button press that happened during
 * the previous recompute.
 * The obvious drawback is that when nothing needs
 * to be done the program takes a lot of CPU just to
 * check that, indeed, nothing needs to be done
 * Possible fix : (not allowed by the constraints
 * of this project)
 * use something like 'usleep(500);' */
int	ft_redraw_as_needed(void *state)
{
	t_state	*s;

	s = (t_state *) state;
	if (s->needs_recompute)
		ft_redraw(s->win, s->im, s->active, s->f);
	s->needs_recompute = 0;
	return (0);
}
