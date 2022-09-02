# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 22:06:53 by abouazi           #+#    #+#              #
#    Updated: 2022/09/01 18:50:38 by abouazi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror               
RM = rm -rf
HEADER = $(addprefix includes/, philo.h)


UTILS		= $(addprefix utils/, atoi time print retard)
INIT		= $(addprefix init/, initial)
PARSING		= $(addprefix parsing/, checker)
EXEC		= $(addprefix exe/, start routine supervisor)
FILES		= $(addprefix src/, philo $(INIT) $(UTILS) $(PARSING) $(EXEC))

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