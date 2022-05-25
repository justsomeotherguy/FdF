/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:09:44 by jwilliam          #+#    #+#             */
/*   Updated: 2022/05/25 12:01:20 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

/*
Keycode definitions
*/
# define KEY_A 			0
# define KEY_S 			1
# define KEY_D 			2
# define KEY_F			3
# define KEY_Z 			6
# define KEY_X 			7
# define KEY_C 			8
# define KEY_V			9
# define KEY_Q 			12
# define KEY_W 			13
# define KEY_E 			14
# define KEY_R			15
# define KEY_ESC 		53
# define KEY_LEFT 		123
# define KEY_RIGHT 		124
# define KEY_DOWN 		125
# define KEY_UP 		126

/*
Define MAX and MIN values
*/
# define MAX 			2147483647
# define MIN 			-2147483648

/*
Define Window Dimensions and Settings
*/
# define WIN_WIDTH 		1280
# define WIN_HEIGHT 	720
# define WIN_TITLE 		"fdf"

/*
Define Menu Text Colours
*/
# define TEXT_A			0xFFFFFF
# define TEXT_B			0xFF8000

/*
Define Mono Colours
*/
# define MONO_25		0x404040
# define MONO_50 		0x808080
# define MONO_75 		0xBFBFBF
# define MONO_100 		0xFFFFFF
# define MONO_BG 		0x1A1A1A

# define VP_25			0x8E00F2
# define VP_50	 		0x6A3CF2
# define VP_75	 		0x23B5F2
# define VP_100 		0x00F2F2
# define VP_BG1 		0x3E175F
# define VP_BG2			0xDA63DF

typedef struct s_map_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}	t_map_point;

typedef struct s_map
{
	int					rows;
	int					columns;
	int					max_z;
	int					min_z;
	t_map_point			**point;
}	t_map;

typedef struct s_image
{
	void				*image;
	char				*address;
	int					width;
	int					height;
	int					bpp;
	int					l_size;
	int					endian;
}	t_image;

typedef struct s_cam
{
	int					x_trans;
	int					y_trans;
	double				x_rot;
	double				y_rot;
	double				z_rot;
	float				z_divisor;
	int					zoom;
	int					projection;
}	t_cam;

typedef struct s_mlx_inst
{
	void				*mlx;
	void				*mlx_win;
}	t_mlx_inst;

typedef struct s_main
{
	t_mlx_inst			*mlx_inst;
	t_image				*image;
	t_cam				*cam;
	t_map				*map;
}	t_main;

/*
cam_change.c
*/
void		change_height(int key, t_main *main);
void		rotate(int key, t_main *main);
void		translate(int key, t_main *main);
void		zoom(int key, t_main *main);
void		change_projection(int key, t_main *main);

/*
cam_reset.c
*/
void		reset_cam(int key, t_main *main);

/*
color.c
*/
void		set_color(t_map *map);
int			get_color(t_map_point cur, t_map_point start, t_map_point end,
				t_map_point delta);
int			read_color(char *data);

/*
color_utils.c
*/
double		get_percent(int start, int end, int current);
int			get_light(int start, int end, double percent);

/*
draw_map.c
*/
void		draw_map(t_map *map, t_cam *cam, t_mlx_inst *mlx_i,
				t_image *image);

/*
draw_line.c
*/
void		draw_line(t_map_point point1, t_map_point point2, t_image *image);

/*
error.c
*/
void		err_bad_args(void);
void		err_bad_file(void);
void		err_init(void);

/*
init_cam.c
*/
t_cam		*init_cam(t_map *map);

/*
init_image.c
*/
t_image		*init_image(t_mlx_inst *mlx, int width, int height);

/*
init_main.c
*/
t_main		*init_main(void);

/*
init_mlx.c
*/
t_mlx_inst	*init_mlx(void);

/*
init_map.c
*/
t_map		*init_map(void);

/*
key_input.c
*/
int			key_input(int key, void *param);

/*
menu.c
*/
void		print_menu(t_mlx_inst *mlx_i);

/*
projection.c
*/
t_map_point	projection(t_map_point point, t_map *map, t_cam *cam);

/*
read_map.c
*/
int			read_map(int fd, t_map *map);

/*
read_map_util.c
*/
void		set_max_height(t_map_point row, t_map *map);
t_map_point	set_point(int col, int row, char *data);
char		**check_row_data(t_map *map, char **split);

/*
close_win.c
*/
int			close_win(t_main *main);

/*
mlx_hooks.c
*/
void		set_mlx_hooks(t_main *main);

/*
utils.c
*/
void		free_array(char **arr);

#endif