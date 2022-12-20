//
//  err_keys_exit.h
//  fdf_orginized_well
//
//  Created by Yuliia Demura on 10/5/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#ifndef err_keys_exit_h
#define err_keys_exit_h

# define ESC 53

# include <stdlib.h>
# include <unistd.h>

typedef enum e_error_handling
{
	OK = 0,
	ERR = -404
}	t_error_handling;

typedef struct s_hook
{
	void	*mlx_ptr;
	void	*window_ptr;
	void	*img_ptr;
}			t_hook;

void	exit_beautifully(const char *message);
int		close_window(t_hook *hook);
int		key_press(int keycode, t_hook *hook);

#endif /* err_keys_exit_h */
