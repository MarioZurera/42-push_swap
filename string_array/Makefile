# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/02 01:27:23 by mzurera-          #+#    #+#              #
#    Updated: 2024/08/02 23:45:37 by mzurera-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# COMMANDS #
CC				= clang
LIBC			= ar rcs
CFLAGS			= -Wall -Wextra -Werror #-g -fsanitize=address
RM				= rm -f
RM_DIR			= rm -rf

# DIRECTORIES #
SRC_DIR			= src
INC_DIR			= includes

# NAME #
NAME			= libstrarr.a

# SOURCE #
SRC_FILE	= create_string_array.c	\
			  get_string_array.c	\
			  len_string_array.c	\
			  free_string_array.c	\
			  clone_string_array.c	\
			  map_string_array.c	\
			  every_string_array.c	\
			  parse_string_array.c	\
			  free_i32_array.c		\
			  ft_strdup.c

SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILE))
OBJ			= $(SRC:.c=.o)

# COLORS #
C_GREEN			= \033[0;32m
C_RED			= \033[0;31m
C_BLUE			= \033[0;34m
C_DEF			= \033[0m

.c.o:
	@$(CC) $(CFLAGS) -c $< -I ./$(INC_DIR) -o $@

$(NAME): $(OBJ)
	$(LIBC) $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all .c.o clean fclean re