/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:40:25 by jwilliam          #+#    #+#             */
/*   Updated: 2022/05/25 13:21:06 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Main entry function of the program.
After initializing structs, passes opened file descriptor to read_map().
If reading map was successful, passes map struct to draw_map() function and
establishes hooks.
Passes resulting struct settings to the mlx_loop.
*/
int	main(int argc, char **argv)
{
	int				fd;
	t_main			*main;

	if (argc != 2)
		err_bad_args();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		err_bad_file();
	main = init_main();
	main->map = init_map();
	if (read_map(fd, main->map) != 1)
		err_bad_file();
	main->image = init_image(main->mlx_inst, WIN_WIDTH, WIN_HEIGHT);
	main->cam = init_cam(main->map);
	draw_map(main->map, main->cam, main->mlx_inst, main->image);
	set_mlx_hooks(main);
	mlx_loop(main->mlx_inst->mlx);
	return (0);
}
