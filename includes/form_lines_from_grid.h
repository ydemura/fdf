//
//  form_lines_from_grid.h
//  fdf_orginized_well
//
//  Created by Yuliia Demura on 10/5/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#ifndef form_lines_from_grid_h
#define form_lines_from_grid_h

# include "colors.h"
# include "read_map.h"
# include "general_used_utils.h"

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	float	w;
}			t_point;

typedef struct s_line
{
	t_point	start;
	t_point	end;
	t_color	color_start;
	t_color	color_end;
}			t_line;

t_line	*form_lines_from_grid(t_grid *grid);
t_cell	grid_get_cell(t_grid const *grid, int col, int row);
t_point	grid_get_point(t_grid const *grid, int col, int row);
t_color	grid_get_color(t_grid const *grid, int col, int row);


#endif /* form_lines_from_grid_h */
