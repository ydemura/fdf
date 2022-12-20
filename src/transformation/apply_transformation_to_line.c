//
//  apply_transformation_to_line.c
//  fdf_orginized_well
//
//  Created by Yuliia Demura on 10/5/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "apply_transformation_isometric.h"

float	sum_up(t_affine_transform matrix, int i, t_point point)
{
	float	new_point_value;

	new_point_value = 0;
	new_point_value += get_num_from_cell(&matrix, i, 0) * point.x;
	new_point_value += get_num_from_cell(&matrix, i, 1) * point.y;
	new_point_value += get_num_from_cell(&matrix, i, 2) * point.z;
	new_point_value += get_num_from_cell(&matrix, i, 3) * point.w;
	return (new_point_value);
}

t_point	affine_transform_apply(t_affine_transform matrix, t_point point)
{
	t_point	transformed_point;

	transformed_point.x = sum_up(matrix, 0, point);
	transformed_point.y = sum_up(matrix, 1, point);
	transformed_point.z = sum_up(matrix, 2, point);
	transformed_point.w = sum_up(matrix, 3, point);
	return (transformed_point);
}

void	apply_tranformation_to_whole_line(t_affine_transform matrix,
		int num_of_lines, t_line *lines, t_line *iso_lines)
{
	int	i;

	i = 0;
	while (i < num_of_lines)
	{
		iso_lines[i].start = affine_transform_apply(matrix, lines[i].start);
		iso_lines[i].end = affine_transform_apply(matrix, lines[i].end);
		iso_lines[i].color_start = lines[i].color_start;
		iso_lines[i].color_end = lines[i].color_end;
		i++;
	}
}
