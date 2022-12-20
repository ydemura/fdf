//
//  form_image_in_window.h
//  fdf_orginized_well
//
//  Created by Yuliia Demura on 10/5/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#ifndef form_image_in_window_h
# define form_image_in_window_h

# include "transform_lines.h"
# include "mlx.h"

typedef struct s_img_point
{
	float	x;
	float	y;
	float	z;
	t_color	color;
}			t_img_point;

typedef struct s_img
{
	void	*img_ptr;
	float	*depth_ptr;
	char	*address;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
	int		img_widht;
	int		img_height;
}			t_img;

int		form_image_in_window(t_hook *hook, t_line *iso_lines,
								 int num_lines, t_adjustments *add);
void	my_line_draw(t_img *img, t_img_point start, t_img_point end);
void	my_pixel_put(t_img *img, t_img_point pixel);

#endif /* form_image_in_window_h */
