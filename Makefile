# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 14:18:22 by jwilliam          #+#    #+#              #
#    Updated: 2022/05/25 11:57:18 by jwilliam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIB = libft
LBX = minilibx_macos
#LBX = minilibx-linux

INCL = includes
INCL_LIB = ./$(LIB)/$(INCL)
LINK_LIB = -L$(LIB) $(LIB)/$(LIB).a
INCL_MLX = ./$(LBX)
LINK_MLX = -L$(LBX) -l mlx
#LINK_MLX = -L$(LBX) $(LBX)/libmlx.a
INCL_ALL = -I$(INCL_LIB) -I$(INCL_MLX) -I$(INCL)

CC = gcc

FLAGS = -Wall -Werror -Wextra
MLX_FL = -framework OpenGL -framework Appkit
#MLX_FL = -L/usr/lib -lXext -lX11 -lm -lz

RM = rm -rf

FILES = main.c \
		cam_change.c \
		cam_reset.c \
		close_win.c \
		color.c \
		color_utils.c \
		draw_line.c \
		draw_map.c \
		error.c \
		init_cam.c \
		init_image.c \
		init_main.c \
		init_map.c \
		init_mlx.c \
		key_input.c \
		menu.c \
		mlx_hooks.c \
		projection.c \
		read_map.c \
		read_map_util.c \
		utils.c \


OBJS_NAME = $(FILES:.c=.o)

OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
SRCS = $(addprefix $(SRC_DIR), $(FILES))
SRC_DIR = srcs/
OBJS_DIR = objs/

all: $(NAME)

$(NAME): $(OBJS)
		@$(MAKE) -C ./$(LIB)
		@$(MAKE) -C ./$(LBX)
#		@$(CC) $(FLAGS) $(OBJS) $(LINK_LIB) $(LINK_MLX) -o $@
		@$(CC) $(FLAGS) $(OBJS) $(LINK_LIB) $(LINK_MLX) $(MLX_FL) -o $@
		@echo "\033[32m████████████████████████████"
		@echo "\033[32m█████    \033[39mfdf created   \033[32m█████"
		@echo "\033[32m████████████████████████████ \033[39m"

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
		@mkdir -p $(OBJS_DIR)
		@$(CC) $(FLAGS) -o $@ -c $< $(INCL_ALL)

clean:
		@$(MAKE) clean -C ./$(LIB)
		@$(RM) $(OBJS)
		@$(RM) $(OBJS_DIR)
		@echo "\033[33m████████████████████████████"
		@echo "\033[33m█████   \033[39mcleaned  fdf   \033[33m█████"
		@echo "\033[33m█████   \033[39mobject files   \033[33m█████"		
		@echo "\033[33m████████████████████████████ \033[39m"

fclean:	clean
		@$(MAKE) fclean -C ./libft		
		@$(RM) $(NAME)
		@$(RM) $(NAME).a
		@echo "\033[33m████████████████████████████"
		@echo "\033[33m█████      \033[39mcleaned     \033[33m█████"
		@echo "\033[33m█████   \033[39mfdf.a  files   \033[33m█████"		
		@echo "\033[33m████████████████████████████ \033[39m"

re: fclean all

.PHONY: clean fclean all re