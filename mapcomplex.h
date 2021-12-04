#ifndef MAPCOMPLEX_H
# define MAPCOMPLEX_H

# include <stdlib.h>
# include "ft_complex.h"
# include "im_buffer.h"

/* complex map type 
 * f is a fun from complex space
 * to rgb color space (as ints)
 * 'data' is used for extra parameters
 * to the function 
 * note : be careful to free data if
 * alloced */
typedef struct s_cmap
{
	void	*data;
	int		(*f)(t_cpx, void *);
}	t_cmap;

void	ft_set_map(t_cmap *map, int (*f)(t_cpx, void *), void *data);

/* apply map, ie return f(z, map->data) */
int		ft_apply_cmap(t_cmap *map, t_cpx z);

/* for a w by h image write (to the image)
 * the result of maping the complex numbers in :
 * [topleft.re, topleft.re + w * pixsz] x [topleft.im, topleft.im + h * pixsz]
 * to colors using f */
void	ft_mapc(t_im *im, t_cpx topleft, double pixsz, t_cmap *f);

#endif
