//
//  grid_get_color_cell_point.c
//  fdf_orginized_well
//
//  Created by Yuliia Demura on 10/5/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "form_lines_from_grid.h"

t_cell	grid_get_cell(t_grid const *grid, int col, int row)
{
	t_cell	cell;

	cell = grid->cells[grid->x_line_size * row + col];
	return (cell);
}

t_point	grid_get_point(t_grid const *grid, int col, int row)
{
	t_point	point;

	point.x = col;
	point.y = row;
	point.z = grid_get_cell(grid, col, row).z;
	point.w = 1;
	return (point);
}

t_color	form_color_struct_from_int(unsigned int trgb, float z)
{
	t_color	color;

	if (trgb == 0xFF0000 || trgb == 0x802020)
		color = sunset_orange();
	else if (trgb == 0x0000FF)
		color = spanish_sky_blue();
	else
		color = my_mix_color(caribbean_green(), purple_pizzazz(), z);
	return (color);
}

t_color	grid_get_color(t_grid const *grid, int col, int row)
{
	unsigned int	color;
	t_color			color_struct;

	color = grid_get_cell(grid, col, row).color;
	color_struct = form_color_struct_from_int(color,
			grid_get_cell(grid, col, row).z);
	return (color_struct);
}
