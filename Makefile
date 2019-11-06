# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 12:22:00 by pganglof          #+#    #+#              #
#    Updated: 2019/11/06 16:54:08 by pganglof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PATH = ./srcs/

SRCS_NAME =	ft_printf.c							\
			flag_c/fct_c.c 						\
			flag_c/c_check_wildcard.c 			\
			flag_c/c_chaine_vide.c				\
			flag_c/c_tiret.c 					\
			flag_c/c_nbr.c 						\
			flag_id/fct_id.c 					\
			flag_id/id_zero_point.c				\
			flag_id/id_nbr.c					\
			flag_id/id_point.c					\
			flag_id/id_tiret.c					\
			flag_id/id_zero.c					\
			flag_id/id_tiret_point.c 			\
			flag_id/id_nbr_point.c 				\
			flag_id/id_check_wildcard.c 		\
			flag_id/id_chaine_vide.c 			\
			flag_p/fct_p.c 						\
			flag_p/p_check_wildcard.c 			\
			flag_p/p_tiret.c 					\
			flag_p/p_nbr.c 						\
			flag_p/p_0x.c 						\
			flag_s/fct_s.c 						\
			flag_s/s_tiret.c 					\
			flag_s/s_nbr.c 						\
			flag_s/s_free.c 					\
			flag_s/s_tiret_point.c 				\
			flag_s/s_nbr_point.c 				\
			flag_s/s_check_wildcard.c 			\
			flag_s/s_chaine_vide.c				\
			flag_u/fct_u.c 						\
			flag_u/u_zero_point.c				\
			flag_u/u_nbr.c						\
			flag_u/u_point.c					\
			flag_u/u_tiret.c					\
			flag_u/u_zero.c						\
			flag_u/u_tiret_point.c 				\
			flag_u/u_nbr_point.c 				\
			flag_u/u_check_wildcard.c 			\
			flag_u/u_chaine_vide.c 				\
			flag_x/fct_x.c						\
			flag_x/x_point.c 					\
			flag_x/x_tiret.c 					\
			flag_x/x_nbr.c 						\
			flag_x/x_zero.c 					\
			flag_x/x_nbr_point.c 				\
			flag_x/x_tiret_point.c 				\
			flag_x/x_zero_point.c 				\
			flag_x/x_chaine_vide.c				\
			flag_x/x_check_wildcard.c  			\
			flag_%/fct_pourcentage.c 			\
			flag_%/pourc_check_wildcard.c	 	\
			flag_%/pourc_tiret.c 				\
			flag_%/pourc_nbr.c 					\
			flag_%/pourc_zero.c 				\
			convert_hex.c						\
			recup_flags/match_type.c			\
			recup_flags/init_ptrf.c 			\
			recup_flags/init_lst.c				\
			recup_flags/ft_atoi_printf.c		

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
CFLAGS += -Wall -Wextra -Werror -I $(HEADERS)

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
