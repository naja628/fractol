/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   im_buffer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:31:42 by najacque          #+#    #+#             */
/*   Updated: 2021/12/14 14:31:42 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IM_BUFFER_H
# define IM_BUFFER_H

# include "mlx.h"

/* mlx image + metadata
 * note : width and line_sz are redundant
 * but convenient to both keep */
typedef struct s_im
{
	void	*mlx;
	void	*im;
	void	*data;
	int		height;
	int		width;
	int		line_sz;
	int		bytespp;
	int		big_end;
}	t_im;

/* initialize t_im struct by obtaining a valid image pointer
 * and calling mlx_get_data_addr to fill in the metadata 
 * We assume bits_per_pixel will be a multiple of eight
 * and convert it to the number of bytes */
void	ft_init_im(void *mlx, t_im *im, int width, int height);

/* write a pixel with color 'color' at the x, y position 
 * in the image im */
void	ft_pix_to_im(t_im *im, int x, int y, int color);

#endif
