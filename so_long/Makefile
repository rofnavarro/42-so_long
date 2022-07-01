# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rferrero <rferrero@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 11:48:16 by rferrero          #+#    #+#              #
#    Updated: 2022/06/29 17:17:58 by rferrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	so_long

CC						=	gcc
CCFLAGS					=	-Wall -Wextra -Werror
MLXFLAGS				=	-lmlx -lX11 -lXext

PATH_PRINTF				=	./utils/ft_printf
PRINTF					= 	$(PATH_PRINTF)/libftprintf.a

RM						=	rm -rf

SRC						=	so_long.c \
							$(addprefix utils/, ft_draw.c \
											 ft_error.c \
											 ft_free_handler.c \
											 ft_game.c \
											 ft_init.c \
											 ft_map_check.c \
											 ft_map_validation.c \
											 ft_move.c \
											 ft_read_map.c \
											 ft_window.c)

OBJ						=	$(SRC:%.c=%.o)

all:					$(NAME)

$(NAME):				$(OBJ)
						$(MAKE) -C $(PATH_PRINTF)
						$(CC) $(CCFLAGS) $(OBJ) $(PRINTF) $(MLXFLAGS) -o $(NAME)

clean:
						$(MAKE) -C $(PATH_PRINTF) clean
						$(RM) $(OBJ)

fclean:					clean
						$(MAKE) -C $(PATH_PRINTF) fclean
						$(RM) $(NAME)

re:						fclean all

.PHONY:					all clean fclean re
