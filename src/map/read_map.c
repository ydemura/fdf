//
//  read_map.c
//  fdf_orginized_well
//
//  Created by Yuliia Demura on 10/5/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "read_map.h"

void	separate_color_from_height(char *str, t_cell *cells)
{
	char	**temp;

	temp = ft_split((const char *)str, ',');
	if (str == NULL)
		exit_beautifully("malloc error, yep\nread_map.c:89");
	cells->z = ft_atoi((const char *)temp[0]);
	if (temp[1][0] == '0' && temp[1][1] == 'x')
		cells->color = my_atoi_hex(temp[1]);
	else
		exit_beautifully("error, what the hex?\nread_map.c:94");
	free_tdarray(temp, 2);
}

void	collect_heigt_and_color(char *str, int x, t_cell *cells)
{
	char	**temp_str_array;
	int		i;

	temp_str_array = ft_split((const char *)str, ' ');
	if (temp_str_array == NULL)
		exit_beautifully("malloc error, yep\nread_map.c:105");
	i = 0;
	while (temp_str_array != NULL && i < x)
	{
		if (str_has_unsigned_int_part(temp_str_array[i]) == 1)
			separate_color_from_height(temp_str_array[i], &cells[i]);
		else
		{
			cells[i].z = ft_atoi((const char *)temp_str_array[i]);
			cells[i].color = 0xFFFFFF;
		}
		i++;
	}
	free_tdarray(temp_str_array, x);
}

int	read_strings(int fd, t_grid *grid)
{
	char	*temp_str;
	int		y;
	int		res;

	grid->cells = malloc(grid->x_line_size * grid->y_line_size * 8);
	if (grid->cells == NULL)
		return (ERR);
	y = 0;
	res = 1;
	while (res > 0)
	{
		res = get_next_line(fd, &temp_str);
		if (res < 0)
			return (free_grid(grid));
		if (res == 0)
		{
			free(temp_str);
			return (OK);
		}
		collect_heigt_and_color(temp_str, grid->x_line_size,
			&grid->cells[y * grid->x_line_size]);
		y++;
		free(temp_str);
	}
	return (OK);
}

void	open_to_collect_data(const char *str_path, t_grid *grid)
{
	int	fd;

	fd = open(str_path, O_RDONLY);
	if (fd == -1)
		exit_beautifully("ooops, open failed us\nread_map.c:151");
	if (read_strings(fd, grid) == ERR)
		exit_beautifully("ooops, read failed us\nread_map.c:135");
	if (close(fd) < 0)
		exit_beautifully("ooops, close failed us\nread_map.c:154");
}

int	read_map(const char *str_path, t_grid *grid)
{
	initiate_grid(grid);
	check_grid_size(str_path, grid);
	open_to_collect_data(str_path, grid);
	find_max_min_z(grid);
	return (OK);
}
