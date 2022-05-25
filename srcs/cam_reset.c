/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:15:55 by jwilliam          #+#    #+#             */
/*   Updated: 2022/05/25 15:05:09 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Resets all values to base line in init_cam for cam struct with exception
to projection int.
Draws new adjusted image on screen after.
*/
void	reset_cam(int key, t_main *main)
{
	int			cam_width;
	int			cam_height;

	if (key == KEY_R)
	{
		cam_width = (WIN_WIDTH / main->map->columns) / 2;
		cam_height = (WIN_HEIGHT / main->map->rows) / 2;
		if (cam_width < cam_height)
			main->cam->zoom = cam_width;
		else
			main->cam->zoom = cam_height;
		if (main->cam->zoom < 1)
			main->cam->zoom = 1;
		main->cam->x_rot = 0;
		main->cam->y_rot = 0;
		main->cam->z_rot = 0;
		main->cam->x_trans = 0;
		main->cam->y_trans = 0;
		main->cam->z_divisor = 2;
	}
	draw_map(main->map, main->cam, main->mlx_inst, main->image);
}
