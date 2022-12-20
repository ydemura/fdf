//
//  form_image_in_window.c
//  fdf_orginized_well
//
//  Created by Yuliia Demura on 10/5/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "form_image_in_window.h"

void	draw_image(t_img *img, t_line *iso_lines, int num_lines)
{
	t_img_point	start;
	t_img_point	end;
	int			i;

	i = 0;
	while (i < num_lines)
	{
		start.x = iso_lines[i].start.x;
		start.y = iso_lines[i].start.y;
		start.z = iso_lines[i].start.z;
		start.color = iso_lines[i].color_start;
		end.x = iso_lines[i].end.x;
		end.y = iso_lines[i].end.y;
		end.z = iso_lines[i].end.z;
		end.color = iso_lines[i].color_end;
		my_line_draw(img, start, end);
		i++;
	}
}

int	depth_buff_creting(t_img *img)
{
	int	i;

	img->depth_ptr = malloc(img->img_widht * img->img_height * sizeof(float));
	if (img->depth_ptr == NULL)
		return (ERR);
	i = 0;
	while (i < img->img_widht * img->img_height)
	{
		img->depth_ptr[i] = INFINITY;
		i++;
	}
	return (OK);
}

int	form_image_in_window(t_hook *hook, t_line *iso_lines,
											int num_lines, t_adjustments *add)
{
	t_img	img;
	void	*mlx_window;

	img.img_widht = add->window_w_x;
	img.img_height = add->window_h_y;
	mlx_window = mlx_new_window(hook->mlx_ptr, img.img_widht,
			img.img_height, "my awesome fdf");
	if (mlx_window == NULL)
		return (ERR);
	img.img_ptr = mlx_new_image(hook->mlx_ptr, img.img_widht, img.img_height);
	if (img.img_ptr == NULL)
		return (ERR);
	if (depth_buff_creting(&img) == ERR)
		return (ERR);
	img.address = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	draw_image(&img, iso_lines, num_lines);
	mlx_put_image_to_window(hook->mlx_ptr, mlx_window, img.img_ptr, 0, 0);
	hook->window_ptr = mlx_window;
	hook->img_ptr = img.img_ptr;
	free(img.depth_ptr);
	free(iso_lines);
	return (OK);
}
