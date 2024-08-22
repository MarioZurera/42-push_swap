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
CFLAGS			= -Wall -Wextra -Werror -g -fsanitize=address
RM				= rm -f
RM_DIR			= rm -rf

# DIRECTORIES #
SRC_DIR			= src
INC_DIR			= includes
TEST_DIR		= test
LIB_DIR			= libft
UNITY_DIR		= unity/src

# LIBRARIES #
LIBFT			= libft.a

# NAME #
NAME			= push_swap
CAP_NAME		= $(shell echo $(NAME) | awk '{print toupper(substr($$0, 1, 1)) substr($$0, 2)}')
TEST_NAME		= my_test

# SOURCE FILES #
STANDARD		= lexer.c init.c error.c parser.c stack.c
MAIN			= main.c
#BONUS			=
BONUS_MAIN		= main_bonus.c
TEST			= test.c
UNITY			= unity.c

# STANDARD #
STANDARD_SRC	= $(addprefix $(SRC_DIR)/, $(STANDARD))
STANDARD_SRC   += $(addprefix $(SRC_DIR)/, $(MAIN))
STANDARD_OBJ	= $(STANDARD_SRC:.c=.o)

# BONUS #
BONUS_SRC		= $(addprefix $(SRC_DIR)/, $(BONUS))
BONUS_SRC	   += $(addprefix $(SRC_DIR)/, $(BONUS_MAIN))
BONUS_OBJ		= $(BONUS_SRC:.c=.o)

# TEST #
TEST_SRC			= $(addprefix $(SRC_DIR)/, $(STANDARD))
TEST_SRC		   += $(addprefix $(TEST_DIR)/, $(TEST))
TEST_SRC		   += $(addprefix $(UNITY_DIR)/, $(UNITY))
TEST_OBJ			= $(TEST_SRC:.c=.o)

# COLORS #
C_GREEN			= \033[0;32m
C_RED			= \033[0;31m
C_BLUE			= \033[0;34m
C_DEF			= \033[0m


###############################################################################
# ====================== # Makefile done by mzurera- # ====================== #
###############################################################################


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(UNITY_DIR) -c $^ -o $@

$(NAME): $(STANDARD_OBJ)
	@echo "$(C_BLUE)Builing $(NAME)...$(C_DEF)"
	@make all -s -C ./$(LIB_DIR)/
	@$(CC) $(CFLAGS) $(STANDARD_OBJ) -L./$(LIB_DIR) ./$(LIB_DIR)/$(LIBFT) -o $(NAME)
	@echo "$(C_GREEN)$(CAP_NAME) built and ready to go!$(C_DEF)"

clean:
	@$(RM) */*.o */*/*.o
	@make clean -s -C $(LIB_DIR)
	@echo "$(C_RED)Cleaned objects!$(C_DEF)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@$(RM) $(TEST_NAME)
	@make fclean -s -C $(LIB_DIR)
	@echo "$(C_RED)Cleaned $(NAME) program!$(C_DEF)"

re: fclean all

bonus: $(BONUS_OBJS) $(BONUS_MAIN_OBJ)
	@echo "$(C_BLUE)Builing $(NAME) with bonus...$(C_DEF)"
	@make all -s -C ./$(LIB_DIR)/
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(BONUS_MAIN_OBJ) -L./$(LIB_DIR) ./$(LIB_DIR)/$(LIBFT) -o $(NAME)
	@echo "$(C_GREEN)$(CAP_NAME) built and ready to go!$(C_DEF)"

test: $(TEST_OBJ)
	@+make all -s -C ./$(LIB_DIR)/
	@$(CC) $(CFLAGS) $(TEST_OBJ) -L./$(LIB_DIR) ./$(LIB_DIR)/$(LIBFT) -o $(TEST_NAME)
	@echo "=================== RUNNING TESTS ==================="
	@./$(TEST_NAME)
	@echo "=================== TESTS COMPLETE =================="

test_bonus: $(BONUS_OBJS) $(TEST_OBJS)
	@+make all -s -C ./$(LIB_DIR)/
	@+make all -s -C ./$(LIB_TEST_DIR)/
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(TEST_OBJS) -L./$(LIB_DIR) -lft -o $(TEST_NAME)
	@echo "=================== TEST COMPILED ==================="
	@./$(TEST_NAME)
	@echo

.PHONY: all bonus clean fclean re test test_bonus .c.o