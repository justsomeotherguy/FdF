/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:27:50 by jwilliam          #+#    #+#             */
/*   Updated: 2022/05/25 13:36:46 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Exits the program if the arguments received are not equal to 2.
*/
void	err_bad_args(void)
{
	ft_putstr_fd("Error : incorrect usage", 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Usage - ./fdf <path/file.fdf>", 1);
	ft_putchar_fd('\n', 1);
	exit(1);
}

/*
Exits the program if the file was a bad path or if it was not found.
*/
void	err_bad_file(void)
{
	ft_putstr_fd("Error : unable to open file or bad file", 1);
	ft_putchar_fd('\n', 1);
	exit(1);
}

/*
Exits the program if mallocs fails.
*/
void	err_init(void)
{
	ft_putstr_fd("Error : Failed to initialize", 1);
	ft_putchar_fd('\n', 1);
	exit(1);
}
