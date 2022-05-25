/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:53:21 by jwilliam          #+#    #+#             */
/*   Updated: 2022/05/25 13:14:08 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Initiazes the cam struct.
Allocates memory of the struct and defines default values.
Returns the created struct.
*/
t_cam	*init_cam(t_map *map)
{
	t_cam		*cam;
	int			cam_width;
	int			cam_height;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (!cam)
		err_init();
	cam_width = (WIN_WIDTH / map->columns) / 2;
	cam_height = (WIN_HEIGHT / map->rows) / 2;
	if (cam_width < cam_height)
		cam->zoom = cam_width;
	else
		cam->zoom = cam_height;
	if (cam->zoom < 1)
		cam->zoom = 1;
	cam->x_rot = 0;
	cam->y_rot = 0;
	cam->z_rot = 0;
	cam->x_trans = 0;
	cam->y_trans = 0;
	cam->z_divisor = 2;
	cam->projection = 1;
	return (cam);
}
