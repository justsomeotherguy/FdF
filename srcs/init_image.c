/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:06:30 by jwilliam          #+#    #+#             */
/*   Updated: 2022/05/25 13:13:31 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Initiazes the image struct.
Allocates memory or the struct and defines default values.
Sends the created image and address of image to mlx.
Returns the created struct.
*/
t_image	*init_image(t_mlx_inst *mlx, int width, int height)
{
	t_image	*new_image;

	new_image = (t_image *)malloc(sizeof (t_image));
	if (!new_image)
		err_init();
	new_image->width = width;
	new_image->height = height;
	new_image->image = mlx_new_image(mlx->mlx, width, height);
	new_image->address = mlx_get_data_addr(new_image->image, &new_image->bpp,
			&new_image->l_size, &new_image->endian);
	return (new_image);
}
