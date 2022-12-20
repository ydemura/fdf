//
//  read_map_utils.c
//  fdf_orginized_well
//
//  Created by Yuliia Demura on 10/5/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "read_map.h"

int	free_grid(t_grid *grid) //??
{
	if (grid != NULL)
		free(grid->cells);
	return (ERR);
}

void	initiate_grid(t_grid *grid)
{
	grid->x_line_size = 0;
	grid->y_line_size = 0;
}

void	free_tdarray(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

float	my_unmix_float(float a, float b, float t)
{
	float	dist;

	dist = b - a;
	if (dist != 0)
		return (a + t / dist);
	else
		return (0);///	not clear yet if this breaks my code when all z=0
}

void	find_max_min_z(t_grid *grid)
{
	int	i;

	i = 0;
	grid->max_z = -INFINITY;
	grid->min_z = INFINITY;
	while (i < grid->x_line_size * grid->y_line_size)
	{
		if (grid->cells[i].z > grid->max_z)
			grid->max_z = grid->cells[i].z;
		if (grid->cells[i].z < grid->min_z)
			grid->min_z = grid->cells[i].z;
		i++;
	}
	i = 0;
	while (i < grid->x_line_size * grid->y_line_size)
	{
		grid->cells[i].z = my_unmix_float(grid->min_z, grid->max_z,
				grid->cells[i].z);
		i++;
	}
}
