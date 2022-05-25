/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:53:24 by jwilliam          #+#    #+#             */
/*   Updated: 2022/05/25 13:13:39 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Initialize map struct variables.
Allocates memory for the struct and defines 0 equivalent values for the map.
Returns the created struct.
*/
t_map	*init_map(void)
{
	t_map		*init_map;

	init_map = (t_map *)malloc(sizeof(t_map));
	if (!init_map)
		err_init();
	init_map->columns = 0;
	init_map->rows = 0;
	init_map->max_z = MIN;
	init_map->min_z = MAX;
	init_map->point = NULL;
	return (init_map);
}
