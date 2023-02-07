# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 18:45:58 by ykhalil-          #+#    #+#              #
#    Updated: 2023/02/07 19:12:58 by ykhalil-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC 	 = CC
CFLAGS = -Wall -Wextra -Werror
CFILES = ft_printf.c ft_putchar.c ft_putunsigned.c ft_putstr.c ft_puthxd.c ft_putnbr.c
SOURCES = $(CFILES:.c=.o)

%.o: %.c
		@$(CC) $(CFLAGS) -c $?
		
all: $(NAME)

$(NAME): $(SOURCES)
	@$(AR) rcs $@ $?

clean:
	@rm -f $(SOURCES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
