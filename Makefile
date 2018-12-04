# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sregnard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:51:18 by sregnard          #+#    #+#              #
#    Updated: 2018/12/03 08:40:17 by sregnard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit

LIBFT		= 	libft/libft.a

LIBFILL		=	fillit.a

HEADERS		=	-I includes/
HEADERS		+=	-I libft/

SRCDIR		=	srcs/
SRC			= 	$(SRCDIR)main.c
SRC			+=	$(SRCDIR)errors.c
SRC			+=	$(SRCDIR)point.c
SRC			+=	$(SRCDIR)tetriminos.c
SRC			+=	$(SRCDIR)lst_tetriminos.c
SRC			+=	$(SRCDIR)solver.c
SRC			+=	$(SRCDIR)map.c

OBJ			=	$(SRC:.c=.o)
	
CC			=	gcc
	
CFLAGS		=	-Wall -Wextra -Werror -g3

.PHONY		:	all clean fclean re $(LIBFT)

all			:	$(NAME)

$(NAME)		:	$(LIBFT) $(LIBFILL)
	$(CC) $(CFLAGS) $(HEADERS) -o $@ $^

$(LIBFT)	:
	make -C libft/

$(LIBFILL)	: $(OBJ)
	ar rcs $@ $?

%.o			:	%.c
	$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $^

clean		:
	rm -rf $(OBJ)
	make clean -C libft/

fclean		:	clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)
	rm -rf $(LIBFILL)

re			:	fclean all
	make re -C libft/
