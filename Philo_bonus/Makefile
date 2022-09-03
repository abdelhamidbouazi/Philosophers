# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/03 01:44:37 by abouazi           #+#    #+#              #
#    Updated: 2022/09/03 01:49:30 by abouazi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror               
RM = rm -rf


HEADER 		= $(addprefix includes/, philo_bonus.h)
UTILS		= $(addprefix utils/, )
INIT		= $(addprefix init/, )
PARSING		= $(addprefix parsing/, )
EXEC		= $(addprefix exe/, )
FILES		= $(addprefix src/, philo_bonus $(INIT) $(UTILS) $(PARSING) $(EXEC))

SRC			= $(FILES:=.c)

OBJ = $(SRC:.c=.o)

%.o: %.c HEADER
	CC $(CFLAGS) -c $< -o $@


$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(OBJ) $(NAME)

re : fclean all