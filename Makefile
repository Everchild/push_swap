# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/15 17:13:45 by sbrochar          #+#    #+#              #
#    Updated: 2017/12/08 04:40:48 by sbrochar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap

INC_DIR = ./inc
SRC_DIR = ./src
OBJ_DIR = ./obj

LIB_DIR = ./libft
LIB_INC = $(LIB_DIR)/inc

SRC1 = main_checker.c
SRC2 = main_pswap.c \
	   choose_algo.c \
	   small_list.c \
	   find_n_edge.c \
	   push_n_a.c \
	   push_n_b.c \
	   sort_insert.c
SRC_COMMON = linked_list.c \
			 parsing_args.c \
			 instructions.c

OBJ1 = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC1))
OBJ2 = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC2))
OBJ_COMMON = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_COMMON))

CC = clang
CFLAGS = -g -c -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIB_INC)
LFLAGS = -L$(LIB_DIR) -lft

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1) $(OBJ_COMMON)
	make -C $(LIB_DIR)
	$(CC) -o $@ $^ $(LFLAGS)

$(NAME2): $(OBJ2) $(OBJ_COMMON)
	make -C $(LIB_DIR)
	$(CC) -o $@ $^ $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	make -C $(LIB_DIR) clean
	rm -f $(OBJ1) $(OBJ2) $(OBJ_COMMON)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME1)
	rm -f $(NAME2)

re: fclean all

.PHONY: all clean fclean re
