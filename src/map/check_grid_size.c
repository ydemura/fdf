//
//  check_grid_size.c
//  fdf_orginized_well
//
//  Created by Yuliia Demura on 10/5/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "read_map.h"

int	count_x_in_line(char *str)
{
	int		i;
	int		x_in_line;
	char	**temp;

	i = 0;
	x_in_line = 0;
	temp = ft_split((const char *)str, ' ');
	if (temp == NULL)
		return (ERR);
	while (temp[i] != NULL)
	{
		x_in_line++;
		i++;
	}
	free_tdarray(temp, i);
	return (x_in_line);
}

int	compare_x_max_and_new_x(int x_max, t_grid *grid)
{
	if (grid->x_line_size == 0)
		grid->x_line_size = x_max;
	else if (grid->x_line_size != 0 && grid->x_line_size != x_max)
	{
		grid->x_line_size = ERR;
		return (ERR);
	}
	else
		grid->x_line_size = x_max;
	return (0);
}

int	check_size_x(int res, int fd, t_grid *grid)
{
	char	*temp_str;
	int		x_max;

	temp_str = NULL;
	if (res > 0)
	{
		res = get_next_line(fd, &temp_str);
		if (res == 0)
		{
			free(temp_str);
			return (0);
		}
		x_max = count_x_in_line(temp_str);
		compare_x_max_and_new_x(x_max, grid);
		if (temp_str != NULL)
			free(temp_str);
		if (grid->x_line_size == ERR || res < 0)
			return (ERR);
	}
	return (res);
}

void	loop_through_file(int fd, t_grid *grid)
{
	int	res;

	res = 1;
	while (res > 0)
	{
		res = check_size_x(res, fd, grid);
		if (res < 0 || grid->x_line_size == ERR)
			exit_beautifully("OOOPS, error...\nsize_map.c:91");
		if (res > 0)
			grid->y_line_size++;
	}
}

int	check_grid_size(const char *str_path, t_grid *grid)
{
	int	fd;

	fd = open(str_path, O_RDONLY);
	if (fd == -1)
		exit_beautifully("ooops, open failed us\n size_map.c:104");
	loop_through_file(fd, grid);
	if (close(fd) < 0)
		exit_beautifully("error...\nsize_map.c:107");
	return (0);
}
