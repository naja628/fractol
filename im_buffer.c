/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   im_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:31:33 by najacque          #+#    #+#             */
/*   Updated: 2021/12/14 14:31:33 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "im_buffer.h"

/** in .h **/
/* mlx image + metadata */
//typedef struct s_im
//{
//	void	*mlx;
//	void	*im;
//	void	*data;
//	int		height;
//	int		width;
//	int		line_sz;
//	int		bytespp;
//	int		big_end;
//} t_im;

/* initialize t_im struct by obtaining a valid image pointer
 * and calling mlx_get_data_addr to fill in the metadata 
 * note : we assume bits_per_pixel will be a multiple of eight
 * and convert it to the number of bytes */
void	ft_init_im(void *mlx, t_im *t, int width, int height)
{	
	t->im = mlx_new_image(mlx, width, height);
	if (!(t->im))
		return ;
	t->data = mlx_get_data_addr(t->im, &t->bytespp, &t->line_sz, &t->big_end);
	t->height = height;
	t->width = width;
	t->mlx = mlx;
	t->bytespp /= 8;
}

/* write a pixel with color 'color' at the x, y position 
 * in the image im 
 *
 * is there alignment problems with the if? 
 */
void	ft_pix_to_im(t_im *im, int x, int y, int color)
{
	char	*write_addr;
	int		cur_byte;

	if (y >= im->height)
		return ;
	write_addr = im->data + y * im->line_sz + x * im->bytespp;
	cur_byte = 0;
	color = mlx_get_color_value(im->mlx, color);
	if (im->bytespp == (sizeof(unsigned int)))
	{
		*(unsigned int *) write_addr = color;
		return ;
	}
	while (cur_byte < im->bytespp)
	{
		if (im->big_end)
			write_addr[cur_byte] = color >> 8
				* (cur_byte + sizeof(unsigned int) - im->bytespp);
		else
			write_addr[cur_byte] = color >> 8 * cur_byte;
		++cur_byte;
	}
}
