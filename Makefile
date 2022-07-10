# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchew <lchew@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 17:13:24 by lchew             #+#    #+#              #
#    Updated: 2022/05/14 22:01:24 by lchew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# MANDATORY
SRC_DIR = ./
SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, get_next_line get_next_line_utils))
OBJ = $(SRC:%.c=%.o)

# MANDATORY
BNS_DIR = ./
B_SRC = $(addprefix $(BNS_DIR), $(addsuffix .c, get_next_line get_next_line_utils))
B_OBJ = $(BNS:%.c=%.o)

# HEADER
INC = ./
HEAD = -I$(INC)

# COMPILER
#-L ../libft -l ft<-- make the lib file dir able to be accessed anywhere
CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3 $(HEAD)

# LIBRARY
LIBCR = ar -rcs

# REMOVE FILES
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(LIBCR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: fclean
	@$(CC) -Wall -Werror -Wextra -g3 -fsanitize=address -D BUFFER_SIZE=42 $(HEAD) $(SRC) ./main.c && ./a.out

clean:
	@$(RM) $(OBJ) ${B_OBJ}

fclean: clean
	@$(RM) $(NAME) a.out
	@reset

re: fclean all

clean_test:
	@$(RM) test.txt
norme:
	norminette -R CheckForbiddenSourceHeader $(SRC) $(B_SRC) ./get_next_line.h

.PHONY: all clean fclean re norme

#  -fsanitize=address -D BUFFER_SIZE=5
