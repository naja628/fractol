#ifndef VIEWS_H
# define VIEWS_H

# include "ft_complex.h"
# include "utils.h"

/* point of view into the complex plane 
 * note: the image has to be redrawn */
typedef struct s_view
{
	t_cpx	topleft;
	double	pixsz;
}	t_view;

void	ft_set_view(t_view *v, t_cpx topleft, double pixsz);

/* complex number at pixel (x, y) */
t_cpx	ft_cpx_xy(t_view *v, int x, int y);

/* zoom by a factor of 'zoom' st (x, y) is on the same complex
 * before and after the zoom */
void	ft_zoom_view(t_view *v, double zoom, int x, int y);

/* the center of the view will be dx pixels to the right
 * and dy pixel to the bottom */
void	ft_move_around(t_view *v, int dx, int dy);

#endif
