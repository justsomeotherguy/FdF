/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:00:48 by jwilliam          #+#    #+#             */
/*   Updated: 2022/05/25 12:40:44 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Helper function to obtain the percentage between two end int values and 
a current int a value in a double type.
Returns the result in a double type.
*/
double	get_percent(int start, int end, int current)
{
	double		place;
	double		distance;

	place = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return ((place / distance));
}

/*
Helper function used to receive the light value between points.
*/
int	get_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}
