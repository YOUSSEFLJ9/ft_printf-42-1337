# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 23:06:15 by ymomen            #+#    #+#              #
#    Updated: 2023/11/14 02:27:39 by ymomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  ft_managecase.c ft_printf.c ft_printhld.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_putunbr.c ft_putnbr_base.c ft_print_add.c
OBJ = $(SRC:.c=.o)
LIB = ar -rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

%.o : %.c ft_printf.h
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME) : $(OBJ)
	@$(LIB) $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)
	
fclean: clean
	@$(RM) $(NAME)

re: fclean all
	
.PHONY : clean fclean all bonus
