//
//  err_keys_exit.c
//  fdf_orginized_well
//
//  Created by Yuliia Demura on 10/5/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "err_keys_exit.h"
#include "mlx.h"

int	close_window(t_hook *hook)
{
	mlx_destroy_window(hook->mlx_ptr, hook->window_ptr);
	mlx_destroy_image(hook->mlx_ptr, hook->img_ptr);
	exit(0);
}

int	key_press(int keycode, t_hook *hook)
{
	if (keycode == ESC)
		close_window(hook);
	return (0);
}

void	write_str_(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	exit_beautifully(const char *message)
{
	write_str_("\n");
	write_str_(message);
	write_str_("\n");
	exit(9);
}
