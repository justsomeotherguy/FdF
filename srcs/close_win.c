/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:34:50 by jwilliam          #+#    #+#             */
/*   Updated: 2022/05/25 12:38:25 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
When called, closes all mlx instances and free all left over 
structs allocated.
*/
int	close_win(t_main *main)
{
	mlx_destroy_window(main->mlx_inst->mlx, main->mlx_inst->mlx_win);
	free(main->cam);
	free(main->image);
	free_array((char **)main->map->point);
	free(main->map);
	free(main->mlx_inst);
	free(main);
	exit (0);
}
