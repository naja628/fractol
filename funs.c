/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:31:29 by najacque          #+#    #+#             */
/*   Updated: 2021/12/14 14:31:29 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funs.h"

/* in .h */
//typedef struct
//{
//	int niter;
//	t_cpx c;
//	t_colorscheme sch;
//}	t_params;

void	ft_set_params(t_params *params, int niter, t_cpx c)
{
	params->niter = niter;
	params->c = c;
	params->sch = ft_scheme_selector(0);
}

/* iterate z^2 + c from z0 up to 'niter' times */
int	ft_iterate_z2_c(t_cpx c, t_cpx z0, void *data)
{
	t_params	*params;
	double		ratio_i;
	double		r;
	int			i;

	params = (t_params *) data;
	r = ft_modulus(c) + 1;
	i = 0;
	while (i < params->niter && ft_modulus(z0) < r)
	{
		z0 = ft_addc(ft_multc(z0, z0), c);
		++i;
	}
	ratio_i = (double) i / (params->niter);
	return (ft_gradient(params->sch.from, params->sch.to, ratio_i));
}

// to be given to ft_mapc
// z2 + c : mandelbrot -> map c, iterate from 0
// 		  : julia iterate from c 
int	ft_julia(t_cpx z0, void *data)
{
	t_params	*params;

	params = (t_params *) data;
	return (ft_iterate_z2_c(params->c, z0, data));
}

int	ft_mandelbrot(t_cpx c, void *data)
{
	return (ft_iterate_z2_c(c, ft_complex(0, 0), data));
}
