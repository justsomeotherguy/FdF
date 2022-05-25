/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:01:17 by jwilliam          #+#    #+#             */
/*   Updated: 2022/05/25 13:12:27 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Used to output the key that is pressed. Mainly for debug purposes 
to find the keycode for the respective key.
*/
static void	print_key(int key)
{
	ft_putstr_fd("Key Pressed - ", 1);
	ft_putnbr_fd(key, 1);
	ft_putchar_fd('\n', 1);
	return ;
}

/*
Receives key input commands from the mlx key hook event and passes through 
to the relevant function dependant on which key was input.
*/
int	key_input(int key, void *param)
{
	t_main		*main;

	main = (t_main *)param;
	print_key(key);
	if (key == KEY_ESC)
		close_win(main);
	else if (key == KEY_Q || key == KEY_W || key == KEY_A || key == KEY_S
		|| key == KEY_Z || key == KEY_X)
		rotate(key, main);
	else if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT
		|| key == KEY_RIGHT)
		translate(key, main);
	else if (key == KEY_E || key == KEY_D)
		zoom(key, main);
	else if (key == KEY_R)
		reset_cam(key, main);
	else if (key == KEY_C)
		change_projection(key, main);
	else if (key == KEY_F || key == KEY_V)
		change_height(key, main);
	return (0);
}
