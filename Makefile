# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/19 15:25:20 by dsousa            #+#    #+#              #
#    Updated: 2014/01/19 15:31:15 by dsousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
FLAGS = -Wall -Werror -Wextra
SRC = main.c display.c reader.c tools.c wall_detect.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) -L\
	/usr/X11/lib -I /usr/X11/include/ -lmlx -lXext -lX11

clean:
	@/bin/rm -f $(NAME)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
