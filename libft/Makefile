# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 12:22:08 by pganglof          #+#    #+#              #
#    Updated: 2019/11/06 12:44:34 by pganglof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PATH = ./

SRCS_NAME =	ft_strlen.c			\
			ft_strlcat.c		\
			ft_strlcpy.c		\
			ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_bzero.c			\
			ft_memset.c			\
			ft_memmove.c		\
			ft_memcpy.c			\
			ft_memccpy.c		\
			ft_memchr.c			\
			ft_calloc.c			\
			ft_strchr.c			\
			ft_strrchr.c		\
			ft_strmapi.c		\
			ft_substr.c			\
			ft_strjoin.c		\
			ft_strnjoin.c		\
			ft_strtrim.c		\
			ft_strupcase.c		\
			ft_split.c			\
			ft_strnstr.c		\
			ft_itoa.c			\
			ft_uitoa.c			\
			ft_strdup.c			\
			ft_strncmp.c		\
			ft_isalpha.c		\
			ft_isdigit.c		\
			ft_isalnum.c		\
			ft_isascii.c		\
			ft_isprint.c		\
			ft_toupper.c		\
			ft_tolower.c		\
			ft_atoi.c			\
			ft_memcmp.c			\
			ft_strequ.c			\
			ft_lstsize.c		\
			ft_strnlen.c		\
			ft_strdel.c			\
			ft_lstnew.c			\
			ft_putnbr.c			\
			ft_lstlast.c		\
			ft_lstmap.c			\
			ft_lstclear.c		\
			ft_lstdelone.c		\
			ft_putendl.c		\
			ft_isspace.c		\
			ft_charset.c		\
			ft_isupper.c		\
			ft_islower.c		\
			ft_strndup.c		\
			ft_putstr.c			\
			ft_strcmp.c			\
			ft_strcat.c			\
			ft_strstr.c			\
			ft_strncat.c		\
			ft_strmap.c			\
		 	ft_putchar.c		\
			ft_lstadd_front.c	\
			ft_lstadd_back.c	\
			ft_strcpy.c			\
			ft_strncpy.c		\
			ft_memrchr.c		\
			ft_lstiter.c		\
			get_next_line.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
HEADERS = ./
OBJS = $(SRCS:.c=.o)
NAME = libft.a
RM = rm -f
AR = ar
AFLAGS = -sucr
CFLAGS += -Wall -Wextra -Werror -g -I $(HEADERS)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(AFLAGS) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all
.PHONY: all clean fclean re
