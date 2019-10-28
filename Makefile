# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 12:22:00 by pganglof          #+#    #+#              #
#    Updated: 2019/10/28 16:24:10 by pganglof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PATH = ./srcs/

SRCS_NAME =	ft_printf.c			\
			fct_c.c 			\
			fct_id.c 			\
			fct_p.c 			\
			fct_s.c 			\
			fct_u.c 			\
			fct_x.c				\
			match_type.c		\
			init_ptrf.c 		\
			init_lst.c			\
			ft_atoi_printf.c	\
			fill_str_front.c	\
			fill_str_back.c		\
			fill_str_front_back.c	\
			fill_str_back_front.c	\
			check_wildcard.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
HEADERS = ./includes
HEADERS_L = ./libft
OBJS = $(SRCS:.c=.o)
LIB = ./libft/libft.a
NAME = libftprintf.a
RM = rm -f
AR = ar
AFLAGS = -rc
CC = gcc
CFLAGS += -Wall -Wextra -Werror -c -fsanitize=address -g -I $(HEADERS)

all: $(NAME)

$(LIB):
	make -C libft -f Makefile

$(NAME): $(OBJS) $(LIB)
	$(AR) $(AFLAGS) $(NAME) $(OBJS) libft/*.o

clean:
	$(RM) $(OBJS) *.o
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all
.PHONY: all clean fclean re
