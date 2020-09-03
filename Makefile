# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/02 15:53:37 by kcorazon          #+#    #+#              #
#    Updated: 2020/09/02 15:53:39 by kcorazon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cub3D

#===============================================================================

SRC_DIR     = src/
LIB_DIR 	= lib/libft/
MLX_DIR     = lib/mlx/
HDR_DIR		= includes/

#===============================================================================

CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror -O2
HDRFLAGS    = -I$(LIB_DIR)$(HDR_DIR) -I$(MLX_DIR) -I$(HDR_DIR)
LIBFLAGS    = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

#===============================================================================

CUB_HDR     = $(addprefix $(HDR_DIR), cub3d.h)
CUB_SRC     = cub3d.c

#-------------------------------------------------------------------------------

PRS_HDR     = $(addprefix $(HDR_DIR), ft_parser.h)
PRS_SRC     = ft_parser.c

#===============================================================================

.PHONY: all
all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) $(HDRFLAGS) $(LIBFLAGS) src/$(CUB_SRC) src/parser/$(PRS_SRC) $(LIB_DIR)libft.a