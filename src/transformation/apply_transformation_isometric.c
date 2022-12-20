//
//  apply_transformation_isometric.c
//  fdf_orginized_well
//
//  Created by Yuliia Demura on 10/5/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "apply_transformation_isometric.h"

t_affine_transform	transform_to_the_centre(t_affine_transform transform,
			int num_of_lines, t_line *iso_lines, t_adjustments *add)
{
	t_minmax_xy	rect;

	rect = find_maxmin_xy(num_of_lines, iso_lines);
	transform = affine_transform_identity();
	add->tr_x = (add->window_w_x / 2 - (rect.min_x + rect.max_x) / 2);
	add->tr_y = (add->window_h_y / 2 - (rect.min_y + rect.max_y) / 2);
	transform = affine_transform_combine(transform,
			affine_transform_translate(add->tr_x, add->tr_y, 0));
	return (transform);
}

t_affine_transform	scale_to_img_size(t_affine_transform transform,
			int num_of_lines, t_line *iso_lines, t_adjustments *add)
{
	t_minmax_xy	rect;

	rect = find_maxmin_xy(num_of_lines, iso_lines);
	add->scale_x = add->window_w_x / rect.max_x;
	add->scale_y = add->window_h_y / rect.max_y;
	if (add->scale_x < add->scale_y)
		add->scale_y = add->scale_x;
	else
		add->scale_x = add->scale_y;
	add->scale_z = 1;
	transform = affine_transform_identity();
	transform = affine_transform_combine(transform, affine_transform_scale
			(add->scale_x, add->scale_y, add->scale_z));
	return (transform);
}

t_affine_transform	translate_in_corner(t_affine_transform transform,
			int num_of_lines, t_line *iso_lines)
{
	t_minmax_xy	rect;

	rect = find_maxmin_xy(num_of_lines, iso_lines);
	transform = affine_transform_identity();
	transform = affine_transform_combine(transform, affine_transform_translate
			((rect.min_x * -1), (rect.min_y * -1), 0));
	return (transform);
}

t_affine_transform	rotate_scale(t_affine_transform transform, int num_of_lines)
{
	transform = affine_transform_combine(transform,
			affine_transform_rotate_x(degree_to_radian(90 - 35.264)));
	transform = affine_transform_combine(transform,
			affine_transform_rotate_z(degree_to_radian(-45)));
	transform = affine_transform_combine(transform,
			affine_transform_scale(1, 1, sqrtf(num_of_lines) / -10));
	return (transform);
}

t_line	*apply_transformation_isometric(t_line *lines, int num_lines,
			t_adjustments *add)
{
	t_line				*iso_l;
	t_affine_transform	transform;

	transform = affine_transform_identity();
	iso_l = malloc(num_lines * sizeof(t_line));
	if (iso_l == NULL)
		return (NULL);
	transform = affine_transform_combine(transform,
			affine_transform_translate(add->tr_x, add->tr_y, 0));
	transform = rotate_scale(transform, num_lines);
	apply_tranformation_to_whole_line(transform, num_lines, lines, iso_l);
	transform = translate_in_corner(transform, num_lines, iso_l);
	apply_tranformation_to_whole_line(transform, num_lines, iso_l, iso_l);
	transform = scale_to_img_size(transform, num_lines, iso_l, add);
	apply_tranformation_to_whole_line(transform, num_lines, iso_l, iso_l);
	transform = transform_to_the_centre(transform, num_lines, iso_l, add);
	apply_tranformation_to_whole_line(transform, num_lines, iso_l, iso_l);
	return (iso_l);
}
