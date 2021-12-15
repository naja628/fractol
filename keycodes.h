/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:31:43 by najacque          #+#    #+#             */
/*   Updated: 2021/12/15 16:20:29 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

//# define LINUX
//# define MAC
# ifdef MAC

#  define ESC 53
#  define SPC 49
#  define UP 126
#  define DOWN 125
#  define LEFT 123
#  define RIGHT 124
#  define ENTER 36
#  define MS_LEFT 1
#  define MS_RIGHT 2
#  define MS_MIDDLE 3
#  define SCROLL_UP 5
#  define SCROLL_DOWN 4
#  define SCROLL_LEFT 7
#  define SCROLL_RIGHT 6
#  define J 38
#  define K 40
#  define P 35

# endif
# ifdef LINUX

#  define ESC 65307
#  define SPC 32
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
#  define ENTER 65307
#  define MS_LEFT 1
#  define MS_RIGHT 3
#  define MS_MIDDLE 2
#  define SCROLL_UP 4
#  define SCROLL_DOWN 5
#  define SCROLL_LEFT 7
#  define SCROLL_RIGHT 6
#  define J 'j'
#  define K 'k'
#  define P 'p'

# endif

#endif
