/*  
    colors.c
    project FDF

    Created by Yuliia Demura on 13/09/21.
    Copyright © 2021 Yuliia Demura. All rights reserved.
*/

#include "colors.h"

t_color	linen(void)
{
	t_color	color;

	color.alpha = 0x00;
	color.red = 0xfa;
	color.green = 0xf0;
	color.blue = 0xe6;
	return (color);
}

t_color	caribbean_green(void)
{
	t_color	color;

	color.alpha = 0x00;
	color.red = 0x00;
	color.green = 0xcc;
	color.blue = 0x99;
	return (color);
}

t_color	sunset_orange(void)
{
	t_color	color;

	color.alpha = 0x00;
	color.red = 0xfd;
	color.green = 0x5e;
	color.blue = 0x53;
	return (color);
}

t_color	spanish_sky_blue(void)
{
	t_color	color;

	color.alpha = 0x00;
	color.red = 0x00;
	color.green = 0xaa;
	color.blue = 0xe4;
	return (color);
}

t_color	purple_pizzazz(void)
{
	t_color	color;

	color.alpha = 0x00;
	color.red = 0xfe;
	color.green = 0x4e;
	color.blue = 0xda;
	return (color);
}
