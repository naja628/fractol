/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:31:46 by najacque          #+#    #+#             */
/*   Updated: 2021/12/14 14:31:46 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "ft_complex.h"

/* 'convex combination' :
 * map k in [0, 1] to [a, b] linearly */
double	ft_convex_comb(double a, double b, double k);

/* like convex_comb for complex nums */
t_cpx	ft_ccomb(t_cpx z1, t_cpx z2, double k);

/* linear gradient from color0 to color1 
 * expect 0 <= k <= 1 */
int		ft_gradient(int color0, int color1, double k);

#endif
