/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcomplex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:31:34 by najacque          #+#    #+#             */
/*   Updated: 2021/12/14 14:31:34 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapcomplex.h"

/** in .h **/
/* complex map type */
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
