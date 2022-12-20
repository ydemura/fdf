//
//  form_lines_from_grid.c
//  fdf_orginized_well
//
//  Created by Yuliia Demura on 10/5/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "form_lines_from_grid.h"

t_line	line_down(t_grid *grid, int col, int row)
{
	t_line	line;

	line.start = grid_get_point(grid, col, row);
	line.color_start = grid_get_color(grid, col, row);
	line.end = grid_get_point(grid, col, row + 1);
	line.color_end = grid_get_color(grid, col, row + 1);
	return (line);
}

t_line	line_to_right(t_grid *grid, int col, int row)
{
	t_line	line;

	line.start = grid_get_point(grid, col, row);
	line.color_start = grid_get_color(grid, col, row);
	line.end = grid_get_point(grid, col + 1, row);
	line.color_end = grid_get_color(grid, col + 1, row);
	return (line);
}

void	build_lines_from_grid(t_line *lines, t_grid *grid, int i, int j)
{
	int	k;

	k = 0;
	while (j < grid->y_line_size)
	{
		i = 0;
		while (i < grid->x_line_size)
		{
			if (j != grid->y_line_size - 1)
			{
				lines[k] = line_down(grid, i, j);
				k++;
			}
			if (i != grid->x_line_size - 1)
			{
				lines[k] = line_to_right(grid, i, j);
				k++;
			}
			i++;
		}
		j++;
	}
}

t_line	*form_lines_from_grid(t_grid *grid)
{
	t_line	*lines;
	int		number_of_lines;
	int		i;
	int		j;

	number_of_lines = count_lines(grid->x_line_size, grid->y_line_size);
	lines = malloc(number_of_lines * sizeof(t_line));
	i = 0;
	j = 0;
	build_lines_from_grid(lines, grid, i, j);
	return (lines);
}
