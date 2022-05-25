/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:26:53 by jwilliam          #+#    #+#             */
/*   Updated: 2022/05/25 12:59:11 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Create the background for the image.
Allocates all image memory to 0 and replaces all pixels on image space 
with defined background color.
*/
static void	draw_bg(t_image *image)
{
	int		*new_image;
	int		index;

	ft_bzero(image->address, WIN_WIDTH * WIN_HEIGHT * (image->bpp / 8));
	new_image = (int *)(image->address);
	index = 0;
	while (index < (WIN_WIDTH * WIN_HEIGHT))
	{
		new_image[index] = VP_BG1;
		index++;
	}
}

/*
Function used to convert the map coordinates in map struct to positions on
the image screen space.
After setting background color and determining map point colors, go through 
each map point row and column and determine the points to draw with lines
to project to adjacent row and column points.
After determining line positions, using projection() function to determine
where on the screen space points and lines are to be drawn.
After all points are drawn on image, call mlx to display the resulting image 
and draw controls text display.
*/
void	draw_map(t_map *map, t_cam *cam, t_mlx_inst *mlx_i, t_image *image)
{
	int				x;
	int				y;

	draw_bg(image);
	set_color(map);
	x = 0;
	while (x < map->rows)
	{
		y = 0;
		while (y < map->columns)
		{
			if (y + 1 < map->columns)
				draw_line(projection(map->point[x][y], map, cam),
					projection(map->point[x][y + 1], map, cam), image);
			if (x + 1 < map->rows)
				draw_line(projection(map->point[x][y], map, cam),
					projection(map->point[x + 1][y], map, cam), image);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx_i->mlx, mlx_i->mlx_win, image->image, 0, 0);
	print_menu(mlx_i);
}

/*
put underneath drawline projection to add extra diagonal line

	if (x + 1 < map->rows && y + 1 < map->columns)
		draw_line(projection(map->point[x][y], map, cam),
			projection(map->point[x + 1][y + 1], map, cam), image);

*/