/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:28:18 by jwilliam          #+#    #+#             */
/*   Updated: 2022/05/25 12:52:46 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Helper function for draw_line(), used to set error factor values.
*/
static int	set_err(t_map_point delta)
{
	int		err;

	if (delta.x > delta.y)
		err = delta.x;
	else
		err = -delta.y;
	err /= 2;
	return (err);
}

/*
Helper function for draw_line(), used to set sign values.
*/
static t_map_point	set_sign(t_map_point start, t_map_point end)
{
	t_map_point		sign;

	if (start.x < end.x)
		sign.x = 1;
	else
		sign.x = -1;
	if (start.y < end.y)
		sign.y = 1;
	else
		sign.y = -1;
	return (sign);
}

/*
Helper function to return the absolute value of int.

Need to put this in libft.
*/
static int	ft_abs(int num)
{
	if (num < 0)
		num = num * -1;
	return (num);
}

/*
Used to determine if the pixel location is a valid position in the defined
screen space.
If it is valid, use the coordinates and color value to draw the pixel on the
screen position.
*/
static void	put_pixel(t_image *image, int x, int y, int color)
{
	int		index;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		index = (x * image->bpp / 8) + (y * image->l_size);
		image->address[index] = color;
		image->address[++index] = color >> 8;
		image->address[++index] = color >> 16;
	}
}

/*
Using two point values from start to end, determines pixel placement towards
end point using Bresenham's line drawing algorithm. 
After determining the point, find the color from get_color() 
to create the gradient from start to end colors.
*/
void	draw_line(t_map_point start, t_map_point end, t_image *image)
{
	t_map_point		delta;
	t_map_point		sign;
	t_map_point		cur;
	int				err[2];

	delta.x = ft_abs(end.x - start.x);
	delta.y = ft_abs(end.y - start.y);
	sign = set_sign(start, end);
	err[0] = set_err(delta);
	cur = start;
	while (cur.x != end.x || cur.y != end.y)
	{
		put_pixel(image, cur.y, cur.x, get_color(cur, start, end, delta));
		err[1] = err[0];
		if (err[1] > -delta.x)
		{
			err[0] -= delta.y;
			cur.x += sign.x;
		}
		if (err[1] < delta.y)
		{
			err[0] += delta.x;
			cur.y += sign.y;
		}
	}
}
