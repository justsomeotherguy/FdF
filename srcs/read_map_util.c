/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:41:37 by jwilliam          #+#    #+#             */
/*   Updated: 2022/05/25 13:25:32 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
char	**check_row_data(t_map *map, char **split)
{
	int		s_len;
	int		index;
	char	**temp;

	s_len = 0;
	index = 0;
	while (split)
		s_len++;
	if (s_len == map->columns)
		return (split);
	temp = ft_calloc(sizeof(char *), map->columns);
	while (split)
	{
		temp[index] = split[index];
		index++;
	}
	if (index < map->columns)
	{
		temp[index] = "0";
		index++;
	}
	split = temp;
	free(temp);
	return (split);
}
*/

/*
Determines the maximum values of the z points of the map point array, used to
determine color values and camera settings.
*/
void	set_max_height(t_map_point row, t_map *map)
{
	if (row.z > map->max_z)
		map->max_z = row.z;
	if (row.z < map->min_z)
		map->min_z = row.z;
	return ;
}

/*
Creates a map point entry based on values to index its position in the grid 
and determines z height and color values if any from map read data.
*/
t_map_point	set_point(int col, int row, char *data)
{
	t_map_point		ret;

	ret.y = col;
	ret.x = row;
	if (data)
		ret.z = ft_atoi(data);
	else
		ret.z = 0;
	ret.color = read_color(ft_strchr(data, ','));
	return (ret);
}
