/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:20:00 by jwilliam          #+#    #+#             */
/*   Updated: 2022/05/25 13:15:37 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Create hooks for mlx events to pass through to separate functions.
*/
void	set_mlx_hooks(t_main *main)
{
	mlx_hook(main->mlx_inst->mlx_win, 2, 0, key_input, main);
	mlx_hook(main->mlx_inst->mlx_win, 17, 0, close_win, main);
	return ;
}
