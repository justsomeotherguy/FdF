/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:27:07 by jwilliam          #+#    #+#             */
/*   Updated: 2022/05/25 13:13:56 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Initialize the mlx variables and instance.
Returns the mlx instance struct.
*/
t_mlx_inst	*init_mlx(void)
{
	t_mlx_inst		*mlx_inst;

	mlx_inst = (t_mlx_inst *)malloc(sizeof(t_mlx_inst));
	if (!mlx_inst)
		err_init();
	mlx_inst->mlx = mlx_init();
	mlx_inst->mlx_win = mlx_new_window(mlx_inst->mlx, WIN_WIDTH,
			WIN_HEIGHT, WIN_TITLE);
	return (mlx_inst);
}
