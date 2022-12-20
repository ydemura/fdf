/*  
    my_pixel_put.c
    project FDF

    Created by Yuliia Demura on 30/09/21.
    Copyright © 2021 Yuliia Demura. All rights reserved.
*/

#include "form_image_in_window.h"

void	shift_dst(t_color color, char *dst)
{
	unsigned int	alpha;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	alpha = color.alpha;
	red = color.red;
	green = color.green;
	blue = color.blue;
	alpha <<= 24;
	red <<= 16;
	green <<= 8;
	*(unsigned int *)dst = (alpha | red | green | blue);
}

void	my_pixel_put(t_img *img, t_img_point pixel)
{
	char	*dst;
	int		offset;
	int		depth_offset;
	int		x;
	int		y;

	x = round(pixel.x);
	y = round(pixel.y);
	if (x >= img->img_widht || y >= img->img_height || x < 0 || y < 0)
		return ;
	depth_offset = (y * img->img_widht) + x;
	if (img->depth_ptr[depth_offset] >= pixel.z)
		img->depth_ptr[depth_offset] = pixel.z;
	else
		return ;
	offset = y * img->line_size + x * (img->bits_per_pixel / 8);
	dst = img->address + offset;
	shift_dst(pixel.color, dst);
}
