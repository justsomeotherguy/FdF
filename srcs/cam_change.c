/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:50:59 by jwilliam          #+#    #+#             */
/*   Updated: 2022/05/25 12:37:11 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Adjusts the z_divisor in cam struct, used to change the value of z values
of the map.
Draws new adjusted image on screen after.
*/
void	change_height(int key, t_main *main)
{
	if (key == KEY_F)
		main->cam->z_divisor -= 0.1;
	if (main->cam->z_divisor < 0.1)
		main->cam->z_divisor = 0.1;
	if (key == KEY_V)
		main->cam->z_divisor += 0.1;
	if (main->cam->z_divisor > 10)
		main->cam->z_divisor = 10;
	draw_map(main->map, main->cam, main->mlx_inst, main->image);
}

/*
Adjusts x_rot, y_rot and z_rot values in cam struct.
Used to adjust the rotation of the projection on the screen.
Different axis are changed depending on input key.
Draws new adjusted image on screen after.
*/
void	rotate(int key, t_main *main)
{
	if (key == KEY_Q)
		main->cam->x_rot -= 0.05;
	if (key == KEY_W)
		main->cam->x_rot += 0.05;
	if (key == KEY_A)
		main->cam->y_rot -= 0.05;
	if (key == KEY_S)
		main->cam->y_rot += 0.05;
	if (key == KEY_Z)
		main->cam->z_rot -= 0.05;
	if (key == KEY_X)
		main->cam->z_rot += 0.05;
	draw_map(main->map, main->cam, main->mlx_inst, main->image);
}

/*
Adjusts x_trans and y_trans in cam struct.
Used to pan the projection on the screen. 
Direction of movement is dictated by key input.
Draws new adjusted image on screen after.
*/
void	translate(int key, t_main *main)
{
	if (key == KEY_UP)
		main->cam->x_trans -= 10;
	if (key == KEY_DOWN)
		main->cam->x_trans += 10;
	if (key == KEY_LEFT)
		main->cam->y_trans -= 10;
	if (key == KEY_RIGHT)
		main->cam->y_trans += 10;
	draw_map(main->map, main->cam, main->mlx_inst, main->image);
}

/*
Adjusts zoom in cam struct.
If zoom level is less than 1, limit it to 1.
Draws new adjusted image on screen after.
*/
void	zoom(int key, t_main *main)
{
	if (key == KEY_E)
		main->cam->zoom++;
	if (key == KEY_D)
		main->cam->zoom--;
	if (main->cam->zoom < 1)
		main->cam->zoom = 1;
	draw_map(main->map, main->cam, main->mlx_inst, main->image);
}

/*
Toggles projection mode between isometric or parallel in cam struct.
Changes it on input and calls reset_cam() to reset the camera settings
while maintaining projection.
Draws new adjusted image on screen after.
*/
void	change_projection(int key, t_main *main)
{
	if (key == KEY_C)
	{
		if (main->cam->projection == 1)
			main->cam->projection = 0;
		else
			main->cam->projection = 1;
	}
	reset_cam(15, main);
}
