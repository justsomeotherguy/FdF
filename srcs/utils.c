/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:01:54 by jwilliam          #+#    #+#             */
/*   Updated: 2022/05/25 13:29:03 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Helper function used to free an array

Possible add to libft later.
*/
void	free_array(char **arr)
{
	int		index;

	index = 0;
	while (arr[index])
		free(arr[index++]);
	free(arr);
}
