# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sregnard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:51:18 by sregnard          #+#    #+#              #
#    Updated: 2018/12/09 15:27:20 by jdugoudr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fillit

LIBFTDIR		=	libft/
LIBFT			=	$(LIBFTDIR)libft.a

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
SRC				+=	$(SRCDIR)ft_print.c

OBJDIR			=	objs/
OBJ				=	$(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
	
CC				=	gcc	
CFLAGS			=	-Wall -Wextra -Werror
XFLAGS			=

all				: $(LIBFT) $(OBJDIR) $(NAME)

$(NAME)		:	$(OBJ)
	$(CC) $(CFLAGS) $(XFLAGS) $(HEADERS) -o $@ $^ -L libft/ -lft

$(LIBFT)		:
	$(MAKE) -C libft/

$(OBJDIR)	:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o	:	$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $^

clean			:	
	rm -rf $(OBJDIR)
	$(MAKE) clean -C libft/

fclean			:	clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)

re				:	fclean all

cleanfill		:
	rm -rf $(OBJDIR)

fcleanfill		:	cleanfill
	rm -rf $(NAME)

refill			:	fcleanfill all

.PHONY			:	all clean fclean re cleanfill fcleanfill refill $(LIBFT)
