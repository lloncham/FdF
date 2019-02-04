# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lloncham <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/23 12:43:02 by lloncham          #+#    #+#              #
#    Updated: 2019/02/04 15:19:59 by lloncham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAG = -Wall -Wextra -Werror

SRC = main.c read.c tools.c bresenham.c deco.c

OBJECTS = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJECTS)
		$(MAKE) -C libft
		$(MAKE) -C minilibx_macos
		gcc -g -fsanitize=address $(CFLAG) -o $(NAME) $(OBJECTS) -L./libft -lft -g -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit

clean :
		@make -C minilibx_macos clean
		@make -C libft clean
		rm -rf $(OBJECTS) libft.a libmlx.a

fclean : clean
		@rm -f $(NAME)
		@make -C libft fclean

re : fclean all

.PHONY: clean fclean all
