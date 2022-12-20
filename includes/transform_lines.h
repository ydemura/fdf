//
//  transform_lines.h
//  fdf_orginized_well
//
//  Created by Yuliia Demura on 10/5/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#ifndef Header_h
# define Header_h

# include "form_lines_from_grid.h"
# include "transformations.h"

typedef struct s_adjustments
{
	t_minmax_xy	min;
	float		tr_x;
	float		tr_y;
	float		scale_x;
	float		scale_y;
	float		scale_z;
	int			window_h_y;
	int			window_w_x;
}				t_adjustments;

t_line	*transform_lines(const char *path, t_grid *grid, t_adjustments *add);

#endif /* Header_h */
