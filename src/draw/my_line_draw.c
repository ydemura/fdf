//
//  my_line_draw.c
//  fdf_orginized_well
//
//  Created by Yuliia Demura on 10/5/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "form_image_in_window.h"

int	my_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	my_mix_float(float a, float b, float t)
{
	float	dist;

	dist = b - a;
	return (a + t * dist);
}

t_color	my_mix_color(t_color a, t_color b, float t)
{
	t_color	mixed;

	mixed.alpha = my_mix_float(a.alpha, b.alpha, t);
	mixed.red = my_mix_float(a.red, b.red, t);
	mixed.green = my_mix_float(a.green, b.green, t);
	mixed.blue = my_mix_float(a.blue, b.blue, t);
	return (mixed);
}

t_img_point	my_mix_point(t_img_point a, t_img_point b, float t)
{
	t_img_point	mixed;

	mixed.x = my_mix_float(a.x, b.x, t);
	mixed.y = my_mix_float(a.y, b.y, t);
	mixed.z = my_mix_float(a.z, b.z, t);
	return (mixed);
}

void	my_line_draw(t_img *img, t_img_point start, t_img_point end)
{
	float		l;
	float		t;
	float		i;
	t_img_point	k;

	l = my_max((end.x - start.x), (end.y - start.y)) + 1;
	i = 0;
	while (i <= l)
	{
		t = i / l;
		k = my_mix_point(start, end, t);
		k.color = my_mix_color(start.color, end.color, t);
		my_pixel_put(img, k);
		i++;
	}
}
