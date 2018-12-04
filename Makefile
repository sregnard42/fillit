# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sregnard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:51:18 by sregnard          #+#    #+#              #
#    Updated: 2018/12/04 17:05:43 by sregnard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fillit

LIBFT			=	libft/libft.a

LIBFILL			=	fillit.a

HEADERS			=	-I includes/
HEADERS			+=	-I libft/

SRCDIR			=	srcs/
SRC				= 	$(SRCDIR)main.c
SRC				+=	$(SRCDIR)errors.c
SRC				+=	$(SRCDIR)point.c
SRC				+=	$(SRCDIR)tetriminos.c
SRC				+=	$(SRCDIR)lst_tetriminos.c
SRC				+=	$(SRCDIR)solver.c
SRC				+=	$(SRCDIR)map.c

OBJ				=	$(SRC:.c=.o)
	
CC				=	gcc	
CFLAGS			=	-Wall -Wextra -Werror
XFLAGS			=	-g3

all				: $(NAME)

$(NAME)			:	$(LIBFT) $(LIBFILL)
	$(CC) $(CFLAGS) $(XFLAGS) $(HEADERS) -o $@ $^

$(LIBFILL)		:	$(OBJ)
	ar rcs $@ $?

$(LIBFT)		:
	$(MAKE) -C libft/

%.o				:	%.c
	$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $^

clean			:
	rm -rf $(OBJ)

fclean			:	clean
	rm -rf $(NAME)
	rm -rf $(LIBFILL)

re				:	fclean all

cleanlib		:
	$(MAKE) clean -C libft/

fcleanlib		:
	$(MAKE) fclean -C libft/

relib			:
	$(MAKE) re -C libft/

.PHONY			:	all clean fclean re cleanlib fcleanlib relib $(LIBFT)
