//
//  transformations.h
//  fdf_orginized_well
//
//  Created by Yuliia Demura on 10/5/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#ifndef transformations_h
#define transformations_h

# include "form_lines_from_grid.h"

typedef struct s_affine_transform
{
	float	a[16];
}			t_affine_transform;

typedef struct s_minmax_xy
{
	float	min_x;
	float	min_y;
	float	max_x;
	float	max_y;
}			t_minmax_xy;

void				set_num_in_cell(t_affine_transform *matrix, int i, int j, float num);
float				get_num_from_cell(t_affine_transform *matrix, int i, int j);
t_minmax_xy			find_maxmin_xy(int num_of_lines, t_line *lines);

t_affine_transform	affine_transform_translate(float d_x, float d_y, float d_z);
t_affine_transform	affine_transform_scale(float scale_x, float scale_y,
						float scale_z);
t_affine_transform	affine_transform_rotate_x(float rotate_x);
t_affine_transform	affine_transform_rotate_y(float rotate_y);
t_affine_transform	affine_transform_rotate_z(float rotate_z);
t_affine_transform	affine_transform_identity(void);
t_affine_transform	affine_transform_combine(t_affine_transform a,
											 t_affine_transform b);



#endif /* transformations_h */
