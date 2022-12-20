/*  
    transform_lines.c
    project FDF

    Created by Yuliia Demura on 05/10/21.
    Copyright © 2021 Yuliia Demura. All rights reserved.
*/

#include "transform_lines.h"
#include "apply_transformation_isometric.h"

void	form_transform_conditions(t_grid *grid, t_adjustments *add)
{
	add->tr_x = (grid->x_line_size / 2) * -1;
	add->tr_y = (grid->y_line_size / 2) * -1;
	add->window_w_x = 1200;
	add->window_h_y = 800;
}

t_line	*transform_lines(const char *path, t_grid *grid, t_adjustments *add)
{
	t_line	*lines;
	t_line	*iso_lines;

	lines = NULL;
	iso_lines = NULL;
	read_map(path, grid);
	lines = form_lines_from_grid(grid);
	if (lines == NULL)
		return (NULL);
	form_transform_conditions(grid, add);
	iso_lines = apply_transformation_isometric(lines,
			count_lines(grid->x_line_size, grid->y_line_size), add);
	if (lines != NULL)
		free(lines);
	if (iso_lines == NULL)
		return (NULL);
	return (iso_lines);
}
