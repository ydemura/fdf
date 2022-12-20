/*  
    colors.h
    project FDF

    Created by Yuliia Demura on 13/09/21.
    Copyright © 2021 Yuliia Demura. All rights reserved.
*/

#ifndef COLORS_H
# define COLORS_H

# include <stdint.h>

typedef struct s_color
{
	u_int8_t	alpha;
	u_int8_t	red;
	u_int8_t	green;
	u_int8_t	blue;
}				t_color;

t_color linen(void);
t_color caribbean_green(void);
t_color sunset_orange(void);
t_color spanish_sky_blue(void);
t_color purple_pizzazz(void);
t_color	my_mix_color(t_color a, t_color b, float t);

#endif
