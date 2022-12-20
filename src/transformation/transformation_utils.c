//
//  transformation_utils.c
//  fdf_orginized_well
//
//  Created by Yuliia Demura on 10/5/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "transformations.h"

void	set_num_in_cell(t_affine_transform *matrix, int i, int j, float num)
{
	int	index;

	index = 4 * i + j;
	matrix->a[index] = num;
}

float	get_num_from_cell(t_affine_transform *matrix, int i, int j)
{
	float	num;
	int		index;

	index = 4 * i + j;
	num = matrix->a[index];
	return (num);
}

void	find_min_xy(int num_of_lines, t_line *lines, t_minmax_xy *rect)
{
	int	i;

	rect->min_x = INFINITY;
	rect->min_y = INFINITY;
	i = 0;
	while (i < num_of_lines)
	{
		if (lines[i].start.x < rect->min_x)
			rect->min_x = lines[i].start.x;
		if (lines[i].start.y < rect->min_y)
			rect->min_y = lines[i].start.y;
		if (lines[i].end.x < rect->min_x)
			rect->min_x = lines[i].end.x;
		if (lines[i].end.y < rect->min_y)
			rect->min_y = lines[i].end.y;
		i++;
	}
}

void	find_max_xy(int num_of_lines, t_line *lines, t_minmax_xy *rect)
{
	int	i;

	rect->max_x = -INFINITY;
	rect->max_y = -INFINITY;
	i = 0;
	while (i < num_of_lines)
	{
		if (lines[i].start.x > rect->max_x)
			rect->max_x = lines[i].start.x;
		if (lines[i].start.y > rect->max_y)
			rect->max_y = lines[i].start.y;
		if (lines[i].end.x > rect->max_x)
			rect->max_x = lines[i].end.x;
		if (lines[i].end.y > rect->max_y)
			rect->max_y = lines[i].end.y;
		i++;
	}
}

t_minmax_xy	find_maxmin_xy(int num_of_lines, t_line *lines)
{
	t_minmax_xy	rect;

	find_min_xy(num_of_lines, lines, &rect);
	find_max_xy(num_of_lines, lines, &rect);
	return (rect);
}
