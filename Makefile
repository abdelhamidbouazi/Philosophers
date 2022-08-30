# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 22:06:53 by abouazi           #+#    #+#              #
#    Updated: 2022/08/25 20:14:52 by abouazi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME_MANDATORY = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror               
RM = rm -rf

SRC = philo.c checker.c utils.c

OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o)

%.o: %.c philo.h
	CC $(CFLAGS) -c $< -o $@


$(NAME_MANDATORY): $(OBJ_MANDATORY)
	$(CC) $(OBJ_MANDATORY) -o $(NAME_MANDATORY)

all : $(NAME_MANDATORY)

clean :
	$(RM) $(OBJ_MANDATORY)

fclean : clean
	$(RM) $(OBJ_MANDATORY)

re : fclean all