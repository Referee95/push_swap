# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 18:45:58 by ykhalil-          #+#    #+#              #
#    Updated: 2023/02/09 22:16:25 by ykhalil-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRG			= push_swap.c 

SRCS 		= $(PRG:.c=.o)

SRC        =   error.c ft_printf.c ft_split.c ft_printf2.c rules1.c rules2.c \
				the_cases.c utils.c utils1.c utils2.c utils3.c utils4.c
		
BPRG		= checker.c			
BSRCS 		= $(BPRG:.c=.o)
BSRC		= $(SRC:.c=.o)

NAME		= push_swap
CHECKER 	= checker
CFLAGS 		= -Wall -Wextra -Werror

%.o:%.c
	cc -c $(CFLAGS) $<

all: $(NAME)

$(NAME) :$(SRCS) $(BSRC)
			cc $(CFLAGS) -c $^ -o ${NAME}
			
bonus : $(CHECKER)

$(CHECKER): $(BSRCS) $(BSRC)
			cc $(CFLAGS) $^ -o checker

clean:
	@rm -f *.o
fclean:		
	@rm -f *.o $(NAME) $(CHECKER)
re:		fclean all
.PHONE : all clean fclean re bonus