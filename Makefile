# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 18:45:58 by ykhalil-          #+#    #+#              #
#    Updated: 2023/02/08 09:29:41 by ykhalil-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS            =   ft_isalnum.c ft_isprint.c  ft_memcmp.c  ft_strlcat.c  ft_strncmp.c  ft_atoi.c  ft_isalpha.c \
                    ft_memcpy.c  ft_strchr.c  ft_strlcpy.c  ft_strnstr.c  ft_tolower.c  ft_bzero.c  ft_isascii.c \
                    ft_memmove.c  ft_strlen.c  ft_strrchr.c  ft_toupper.c  ft_isdigit.c  ft_memchr.c  ft_memset.c \
                    ft_strdup.c  ft_calloc.c  ft_substr.c  ft_strjoin.c  ft_strtrim.c  ft_split.c  ft_strmapi.c  \
                    ft_striteri.c  ft_itoa.c  ft_putchar_fd.c  ft_putstr_fd.c  ft_putendl_fd.c  ft_putnbr_fd.c  \
					ft_lstnew.c  ft_lstadd_front.c  ft_lstsize.c  ft_lstlast.c  ft_lstadd_back.c  ft_lstdelone.c  \
					ft_lstclear.c  ft_lstiter.c  ft_lstmap.c
DEPS		= libft.h
OBJS		= ${SRCS:.c=.o}
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
RM			= rm -rf
NAME		= libft.a

%.o:%.c ${DEPS} 
			${CC} ${CFLAGS} -c $< -o $@
$(NAME): $(OBJS)
			ar rc ${NAME} $^

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:		fclean all
