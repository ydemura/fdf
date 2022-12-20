//
//  translate_scale_rotate.c
//  fdf_xcode_part
//
//  Created by Yuliia Demura on 18/09/2021.
//

#include "transformations.h"

t_affine_transform	affine_transform_translate(float d_x, float d_y, float d_z)
{
	t_affine_transform	matrix;

	matrix = affine_transform_identity();
	set_num_in_cell(&matrix, 0, 3, d_x);
	set_num_in_cell(&matrix, 1, 3, d_y);
	set_num_in_cell(&matrix, 2, 3, d_z);
	return (matrix);
}

t_affine_transform	affine_transform_scale(float scale_x, float scale_y,
															float scale_z)
{
	t_affine_transform	matrix;

	matrix = affine_transform_identity();
	set_num_in_cell(&matrix, 0, 0, scale_x);
	set_num_in_cell(&matrix, 1, 1, scale_y);
	set_num_in_cell(&matrix, 2, 2, scale_z);
	return (matrix);
}

t_affine_transform	affine_transform_rotate_z(float rotate_z)
{
	t_affine_transform	matrix;

	matrix = affine_transform_identity();
	set_num_in_cell(&matrix, 0, 0, cosf(rotate_z));
	set_num_in_cell(&matrix, 0, 1, -sinf(rotate_z));
	set_num_in_cell(&matrix, 1, 0, sinf(rotate_z));
	set_num_in_cell(&matrix, 1, 1, cosf(rotate_z));
	return (matrix);
}

t_affine_transform	affine_transform_rotate_y(float rotate_y)
{
	t_affine_transform	matrix;

	matrix = affine_transform_identity();
	set_num_in_cell(&matrix, 0, 0, cosf(rotate_y));
	set_num_in_cell(&matrix, 0, 2, -sinf(rotate_y));
	set_num_in_cell(&matrix, 2, 0, sinf(rotate_y));
	set_num_in_cell(&matrix, 2, 2, cosf(rotate_y));
	return (matrix);
}

t_affine_transform	affine_transform_rotate_x(float rotate_x)
{
	t_affine_transform	matrix;

	matrix = affine_transform_identity();
	set_num_in_cell(&matrix, 1, 1, cosf(rotate_x));
	set_num_in_cell(&matrix, 1, 2, sinf(rotate_x));
	set_num_in_cell(&matrix, 2, 1, -sinf(rotate_x));
	set_num_in_cell(&matrix, 2, 2, cosf(rotate_x));
	return (matrix);
}
