# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 20:00:04 by jonascim          #+#    #+#              #
#    Updated: 2022/12/06 14:55:31 by jonascim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
INCLUDE		= includes
LIBFT		= libft
MLX			= minilibx
SRC_DIR		= src/
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g -I
MLXFLAGS	= -framework OpenGL -framework AppKit
RM			= rm -f

#Sources

SRC_FILES	=	main.c read_map.c check_map.c render_game.c movement.c \
				utils.c

SRC 		= 	$(addprefix $(SRC_DIR), $(SRC_FILES))

###

all:		$(NAME)

$(NAME):	$(SRC)
			@make -C $(LIBFT)
			@$(CC) -o $(NAME) $(SRC) -L. $(LIBFT)/libft.a -L. -lmlx $(MLXFLAGS)

clean:
			@make clean -C $(LIBFT)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(LIBFT)/libft.a

re:			fclean all

.PHONY:		all clean fclean re norm
