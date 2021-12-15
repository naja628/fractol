/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_color.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:31:45 by najacque          #+#    #+#             */
/*   Updated: 2021/12/14 14:31:45 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_COLOR_H
# define SELECT_COLOR_H

typedef struct s_colorscheme
{
	int	from;
	int	to;
}	t_colorscheme;

/* go to 'dir'th next colorscheme */
t_colorscheme	ft_scheme_selector(int dir);

#endif
