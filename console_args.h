/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_args.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:31:38 by najacque          #+#    #+#             */
/*   Updated: 2021/12/14 14:31:38 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSOLE_ARGS_H
# define CONSOLE_ARGS_H

# include <limits.h>
# include <unistd.h>

typedef unsigned int	t_uint;
typedef unsigned char	t_uchar;

void	ft_puterr(const char *message);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
double	ft_xatoi(const char *s, int *errcode);

#endif
