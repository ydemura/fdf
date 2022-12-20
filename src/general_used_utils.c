//
//  general_used_utils.c
//  fdf_orginized_well
//
//  Created by Yuliia Demura on 10/5/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "general_used_utils.h"

float	degree_to_radian(float angle)
{
	float	radian;

	radian = (angle * M_PI) / 180;
	return (radian);
}

//int	make_pos_int(float num) //???
//{
//	int	num_int;
//
//	if (num < 0)
//		num = num * -1;
//	num_int = (int)num;
//	return (num_int);
//}

int	count_lines(int x, int y)
{
	int	res;
	int	i;
	int	j;

	res = 0;
	i = 0;
	j = 0;
	while (j < y - 1)
	{
		i = 0;
		while (i < x - 1)
		{
			res += 2;
			i++;
		}
		j++;
	}
	res += x - 1;
	res += y - 1;
	return (res);
}
