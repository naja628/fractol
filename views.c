/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:31:36 by najacque          #+#    #+#             */
/*   Updated: 2021/12/14 14:31:36 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "views.h"

void	ft_set_view(t_view *v, t_cpx topleft, double pixsz)
{
	v->topleft = topleft;
	v->pixsz = pixsz;
}

t_cpx	ft_cpx_xy(t_view *v, int x, int y)
{
	t_cpx	z;

	z = ft_complex(x * v->pixsz, -y * v->pixsz);
	return (ft_addc(v->topleft, z));
}

void	ft_zoom_view(t_view *v, double zoom, int x, int y)
{
	v->topleft = ft_ccomb(ft_cpx_xy(v, x, y), v->topleft, 1 / zoom);
	v->pixsz /= zoom;
}

void	ft_move_around(t_view *v, int dx, int dy)
{
	t_cpx	transla;

	transla = ft_complex(dx * v->pixsz, -dy * v->pixsz);
	v->topleft = ft_addc(v->topleft, transla);
}
