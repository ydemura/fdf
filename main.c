/*  
    main.c
    project FDF

    Created by Yuliia Demura on 5/08/21.
    Copyright © 2021 Yuliia Demura. All rights reserved.
*/

#include "read_map.h"
#include "transform_lines.h"
#include "form_image_in_window.h"

//void	free_struct_lines_grid(t_line *iso_lines, t_grid *grid)
//{
//	free(iso_lines);
//	free(grid->cells);
//}

void	loop_window(t_line *iso_lines, int num_lines, t_adjustments *add)
{
	t_hook	hook;
	int		button_x;
	int		esc;

	esc = 2;
	button_x = 17;
	hook.mlx_ptr = mlx_init();
	form_image_in_window(&hook, iso_lines, num_lines, add);
	mlx_hook(hook.window_ptr, button_x, 0, close_window, &hook);
	mlx_hook(hook.window_ptr, esc, 0, key_press, &hook);
	mlx_loop(hook.mlx_ptr);
}

int	main(int argc, const char *argv[])
{
	t_grid			grid;
	t_line			*iso_lines;
	t_adjustments	add;

	if (argc != 2)
		exit_beautifully("you forgot the argument, but thats OK\nmain.c:52");
	iso_lines = transform_lines(argv[1], &grid, &add);
	if (iso_lines == NULL)
		exit_beautifully("got lost in lines\nmain.c:53");
	free(grid.cells);
	
	
	
	//Im here
	loop_window(iso_lines,
		count_lines(grid.x_line_size, grid.y_line_size), &add);
	return (0);
}
