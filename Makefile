
NAME		=	so_long
CC			=	cc
SRCS		=	srcs/main.c srcs/new_window.c srcs/close_and_destroy.c srcs/keypress.c srcs/map_check.c srcs/mapinit.c srcs/rendering.c  srcs/get_next_line.c srcs/get_next_line_aux.c

				

LIBFT		=	libft/libft.a
CFLAGS		=	-Wall -Wextra -Werror -g 
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)
MLXFLAGS	=	-L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11


ifeq ($(shell uname ), Darwin)
# se for mac usa library shared
LIBFT	=	libft/libft.so
MLXFLAGS	=	-L ./mlx/ -lmlx -framework OpenGL -framework AppKit -lz
endif

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft
			cp $(LIBFT) libft.so
			make -C mlx_linux
			$(CC) $(SRCS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)
			

%o:			%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME) 
			$(RM) *.out
			$(RM) *.so
			make fclean -C libft/
			make clean -C mlx/

re:			fclean all

.PHONY:		all clean fclean re