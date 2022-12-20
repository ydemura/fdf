//
//  read_map.h
//  fdf_orginized_well
//
//  Created by Yuliia Demura on 10/5/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#ifndef read_map_h
#define read_map_h

# include "err_keys_exit.h"
# include "libft.h"
# include <math.h>
# include <fcntl.h>

typedef struct s_cell
{
	unsigned int	color;
	float			z;
}					t_cell;

typedef struct s_grid
{
	int				y_line_size;
	int				x_line_size;
	float			max_z;
	float			min_z;
	t_cell			*cells;
}					t_grid;

int				read_map(const char *str_path, t_grid *grid);
int				check_grid_size(const char *str_path, t_grid *grid);
void			find_max_min_z(t_grid *grid);
unsigned int	my_atoi_hex(char *str);
void			initiate_grid(t_grid *grid);
int				str_has_unsigned_int_part(char *str);
int				free_grid(t_grid *grid);
void			free_tdarray(char **str, int i);

#endif /* read_map_h */
