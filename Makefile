
NAME		=	so_long
CC			=	cc
SRCS		=	srcs/test.c \
				

LIBFT		=	libft/libft.a
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-L ./mlx/ -lmlx -framework OpenGL -framework AppKit -lz
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)

ifeq ($(shell uname), Linux)
# se for linux usa estas flags
MLXFLAGS	=	-L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11
endif

ifeq ($(shell uname ), Darwin)
# se for mac usa library shared
LIBFT	=	libft/libft.so
endif

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft
			cp $(LIBFT) libft.so
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