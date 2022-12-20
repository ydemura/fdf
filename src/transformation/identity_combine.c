//
//  identity_combine.c
//  fdf_xcode_part
//
//  Created by Yuliia Demura on 18/09/2021.
//

#include "transformations.h"

float	collect_num(t_affine_transform a, t_affine_transform b, int i, int j)
{
	int		k;
	float	num;

	k = 0;
	num = 0;
	while (k < 4)
	{
		num += get_num_from_cell(&a, i, k) * get_num_from_cell(&b, k, j);
		k++;
	}
	return (num);
}

t_affine_transform	affine_transform_combine(t_affine_transform a,
														t_affine_transform b)
{
	t_affine_transform	matrix;
	int					i;
	int					j;
	float				num;

	matrix = affine_transform_identity();
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			num = collect_num(a, b, i, j);
			set_num_in_cell(&matrix, i, j, num);
			j++;
		}
		i++;
	}
	return (matrix);
}

t_affine_transform	affine_transform_identity(void)
{
	t_affine_transform	matrix;
	int					i;

	i = 0;
	while (i < 16)
	{
		matrix.a[i] = 0;
		i++;
	}
	matrix.a[0] = 1;
	matrix.a[5] = 1;
	matrix.a[10] = 1;
	matrix.a[15] = 1;
	return (matrix);
}
