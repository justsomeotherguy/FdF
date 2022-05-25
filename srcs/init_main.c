/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:26:54 by jwilliam          #+#    #+#             */
/*   Updated: 2022/05/25 13:09:43 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Initiazes the main struct.
Initializes the mlx instance within main struct.
Returns the created struct.
*/
t_main	*init_main(void)
{
	t_main		*main;

	main = (t_main *)malloc(sizeof(t_main));
	if (!main)
		err_init();
	main->mlx_inst = init_mlx();
	if (!main->mlx_inst)
		err_init();
	return (main);
}
