# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asadanow <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 16:58:17 by asadanow          #+#    #+#              #
#    Updated: 2022/12/16 17:30:11 by asadanow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = ./src/check_args.c \
      ./src/main.c \
      ./src/op_push.c \
      ./src/op_rotate.c \
      ./src/op_revrot.c \
      ./src/op_swap.c \
      ./src/sort_algo.c \
      ./src/sort_algo_utils.c \
      ./src/sort_algo_utils_2.c \
      ./src/sort_algo_utils_opti.c \

LIBDIR = ./libft/

CC = cc -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cd $(LIBDIR) && $(MAKE)
	$(CC) $(OBJ) ./libft/libft.a -o $(NAME)

.c.o:
	$(CC) -c $< -I ./includes -o $@

clean:
	/bin/rm -f $(OBJ)
	cd $(LIBDIR) && $(MAKE) clean

fclean: clean
	/bin/rm -f $(NAME)
	cd $(LIBDIR) && $(MAKE) fclean

re: fclean all
