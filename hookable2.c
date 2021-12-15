/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookable2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:31:32 by najacque          #+#    #+#             */
/*   Updated: 2021/12/14 14:31:32 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hookable.h"

// use to swap the views 
static void	ft_ptr_swap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// TODO deal with multi thing
// note : right now only handle square views
void	ft_toggle_julia(t_state *s, int im_sz, int x, int y)
{
	double	radius;

	if (s->f->f == ft_mandelbrot)
	{
		s->f->f = ft_julia;
		s->params->c = ft_cpx_xy(s->active, x, y);
		radius = 1 + ft_modulus(s->params->c);
		s->passive->topleft = ft_complex(0 - radius, 0 + radius);
		s->passive->pixsz = 2 * radius / im_sz;
	}
	else if (s->f->f == ft_julia)
	{
		s->f->f = ft_mandelbrot;
	}
	ft_ptr_swap((void *) &(s->active), (void *) &(s->passive));
}

void	ft_next_color(t_state *s)
{
	s->params->sch = ft_scheme_selector(1);
}
