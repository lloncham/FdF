NAME = fdf

CFLAG = -Wall -Wextra -Werror

SRC = main.c

OBJECTS = (SRC:.c=.o)

all : $(NAME)

$(NAME) :
		make -C libft
		mv libft/libft.a .
		make -C minilibx_macos
		mv minilibx_macos/libmlx.a .
		gcc $(CFLAG) -o $(NAME) $(SRC) -L./libft -lft -g -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit
clean :
		@make -C minilibx_macos clean
		@make -C libft clean
		rm -rf $(OBJ) libft.a libmlx.a

fclean : clean
		@rm -f $(NAME)
		@make -C libft fclean

re : fclean all
