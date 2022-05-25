/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:46:45 by jwilliam          #+#    #+#             */
/*   Updated: 2022/05/25 12:46:20 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Used to convert hex value received from map parsing into a int value to use
for color information. If there is no color defined within, returns MIN which
is used to convert to default color for projection.
*/
int	read_color(char *data)
{
	static char		hexupper[] = "0123456789ABCDEF";
	static char		hexlower[] = "0123456789abcdef";
	int				num;
	int				index;

	if (!data)
		return (MIN);
	data += 3;
	num = 0;
	while (*data)
	{
		index = 0;
		while (index < 16)
		{
			if (*data == hexupper[index] || *data == hexlower[index])
			{
				num = num * 16 + index;
				break ;
			}
			index++;
		}
		data++;
	}
	return (num);
}	

/*
Sets the color for a map point.
If there is no predefined colors set for the point, sets the color based on
preselected colors dependant on the z height of the point.
*/
void	set_color(t_map *map)
{
	double			percent;
	int				row;
	int				column;

	row = -1;
	while (++row < map->rows)
	{
		column = -1;
		while (++column < map->columns)
		{
			if (map->point[row][column].color == MIN)
			{
				percent = get_percent(map->min_z, map->max_z,
						map->point[row][column].z);
				if (percent < 0.25)
					map->point[row][column].color = VP_25;
				else if (percent < 0.5)
					map->point[row][column].color = VP_50;
				else if (percent < 0.75)
					map->point[row][column].color = VP_75;
				else
					map->point[row][column].color = VP_100;
			}
		}
	}
}

/*
Used to determine the color for a pixel dependant on the current pixel
placement for the line from point start to end. 
*/
int	get_color(t_map_point cur, t_map_point start, t_map_point end,
			t_map_point delta)
{
	int			red;
	int			green;
	int			blue;
	double		percent;

	if (cur.color == end.color)
		return (cur.color);
	if (delta.x > delta.y)
		percent = get_percent(start.x, end.x, cur.x);
	else
		percent = get_percent(start.y, end.y, cur.y);
	red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF,
			percent);
	green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF,
			percent);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}
