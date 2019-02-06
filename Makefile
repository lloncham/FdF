# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lloncham <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/23 12:43:02 by lloncham          #+#    #+#              #
#    Updated: 2019/02/06 17:55:50 by lloncham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAG = -Wall -Wextra -Werror

SRC = main.c read.c tools.c bresenham.c deco.c projections.c

OBJECTS = $(SRC:.c=.o)
	RED=\033[1;31m
	GREEN=\033[1;32m

all : $(NAME)

$(NAME): $(OBJECTS)
		@$(MAKE) -C libft
		@$(MAKE) -C minilibx_macos
		@gcc $(CFLAG) -o $(NAME) $(OBJECTS) -L./libft -lft -g -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit
		@echo "$(GREEN)[✓]Ready!"

clean :
		@make -C minilibx_macos clean
		@make -C libft clean
		rm -rf $(OBJECTS) libft.a libmlx.a
		@echo "$(RED)[✓]Clean!"

fclean : clean
		@rm -f $(NAME)
		@make -C libft fclean
		@echo "$(RED)[✓]All clean!"

re : fclean all

.PHONY: clean fclean all
