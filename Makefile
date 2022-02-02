NAME	=	so_long

SRCS	=	so_long.c get_map.c event_up.c event_down.c out.c display2.c ft_itoa.c ft_strstr.c \
			ft_split.c event_left.c event_right.c init_win.c display1.c check_map.c check_char.c \

GCC		=	gcc -Werror -Wextra -Wall

FLAGS = -lmlx -framework OpenGL -framework AppKit

RM	=	rm -f

all:	$(NAME)

$(NAME):
	@$(GCC) $(SRCS) $(FLAGS) -o so_long
	@echo "\033[1;32m[DONE]"

clean:
	@$(RM)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all