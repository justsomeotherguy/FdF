/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:43:57 by jwilliam          #+#    #+#             */
/*   Updated: 2022/05/25 13:36:01 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Makes a row of map points from the split text from the get_next_line read. 
*/
static t_map_point	*make_row(t_map *map, char **split)
{
	t_map_point		*row;
	int				index;

	if (!split)
		return (NULL);
	if (map->columns == 0)
		while (split[map->columns])
			map->columns++;
	row = ft_calloc(sizeof(t_map_point), map->columns);
	if (row)
	{
		index = 0;
		while (index < map->columns)
		{
			row[index] = set_point(index, map->rows, split[index]);
			set_max_height(row[index], map);
			index++;
		}
	}
	free_array(split);
	return (row);
}

/*
Uses the generated row data to add them into map points array.
*/
static int	add_row(t_map *map, t_map_point *row)
{
	t_map_point		**temp;
	int				index;

	if (!row || row == NULL)
		return (0);
	temp = ft_calloc(sizeof(t_map_point *), map->rows + 2);
	if (!temp)
		return (0);
	index = map->rows;
	temp[index] = row;
	while (index > 0)
	{
		index--;
		temp[index] = map->point[index];
	}
	free(map->point);
	map->point = temp;
	map->rows++;
	return (1);
}

/*
After opening the file, utilize get_next_line() function to read each 
processed line and pass it to helper functions to generate rows based on the 
data received and add them to the map points array.
*/
int	read_map(int fd, t_map *map)
{
	int		gnl_read;
	char	*map_read;

	gnl_read = 1;
	while (gnl_read == 1)
	{
		map_read = get_next_line(fd);
		if (!map_read)
			break ;
		if (add_row(map, make_row(map, ft_split(map_read, ' '))) != 1)
		{
			free(map_read);
			close(fd);
			return (0);
		}
		free(map_read);
	}
	close(fd);
	if (map->rows == 0 && map->columns == 0)
		return (0);
	ft_putstr_fd("Map Loaded.\n", 2);
	return (1);
}
