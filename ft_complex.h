/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:31:39 by najacque          #+#    #+#             */
/*   Updated: 2021/12/14 14:31:39 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPLEX_H
# define FT_COMPLEX_H

# include <math.h>

typedef struct s_complex
{
	double	re;
	double	im;
}	t_cpx;

t_cpx	ft_complex(double re, double im);
t_cpx	ft_addc(t_cpx z, t_cpx w);
t_cpx	ft_multc(t_cpx z, t_cpx w);
double	ft_modulus(t_cpx z);
t_cpx	ft_rot(double theta);

#endif
