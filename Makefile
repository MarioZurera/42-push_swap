# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/02 01:27:23 by mzurera-          #+#    #+#              #
#    Updated: 2024/10/05 18:02:40 by mzurera-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMMANDS #
CC				= clang
CFLAGS			= -Wall -Wextra -Werror -g #-fsanitize=address
RM				= rm -f
RM_DIR			= rm -rf

# DIRECTORIES #
SRC_DIR			= src
INC_DIR			= includes
TEST_DIR		= test
LIB_DIR			= libft
STR_ARR_DIR		= string_array
UNITY_DIR		= unity/src

# LIBRARIES #
LIBFT			= libft.a
STRING_ARRAY	= libstrarr.a

# NAME #
NAME			= push_swap
CAP_NAME		= $(shell echo $(NAME) | awk '{print toupper(substr($$0, 1, 1)) substr($$0, 2)}')
TEST_NAME		= my_test

# SOURCE DIRECTORIES #
LEXER_DIR		= lexer
PARSER_DIR		= parser
STACK_DIR		= stack
MOVEMENTS_DIR	= movements
ERROR_DIR		= error
SORT_DIR		= sort

# SOURCE FILES #
LEXER_SRC		= lexer.c
LEXER			= $(addprefix $(LEXER_DIR)/, $(LEXER_SRC))

PARSER_SRC		= parser.c
PARSER			= $(addprefix $(PARSER_DIR)/, $(PARSER_SRC))

STACK_SRC		= create_stack.c free_stack.c copy_stack.c compare_stack.c \
				  push_stack.c pop_stack.c is_empty_stack.c is_full_stack.c
STACK			= $(addprefix $(STACK_DIR)/, $(STACK_SRC))

MOVEMENTS_SRC	= movement_swap.c movement_push.c movement_rotate.c movement_reverse.c
MOVEMENTS		= $(addprefix $(MOVEMENTS_DIR)/, $(MOVEMENTS_SRC))

ERROR_SRC		= error.c
ERROR			= $(addprefix $(ERROR_DIR)/, $(ERROR_SRC))

SORT_SRC		= sort.c ordered.c invert.c rotate.c greedy.c
SORT			=$(addprefix $(SORT_DIR)/, $(SORT_SRC))

MAIN			= main.c
#BONUS			=
BONUS_MAIN		= main_bonus.c
TEST			= test.c stack.c movements.c
UNITY			= unity.c

# STANDARD #
STANDARD_SRC	= $(addprefix $(SRC_DIR)/, $(MAIN))
STANDARD_SRC   += $(addprefix $(SRC_DIR)/, $(LEXER))
STANDARD_SRC   += $(addprefix $(SRC_DIR)/, $(PARSER))
STANDARD_SRC   += $(addprefix $(SRC_DIR)/, $(STACK))
STANDARD_SRC   += $(addprefix $(SRC_DIR)/, $(MOVEMENTS))
STANDARD_SRC   += $(addprefix $(SRC_DIR)/, $(ERROR))
STANDARD_SRC   += $(addprefix $(SRC_DIR)/, $(SORT))
STANDARD_OBJ	= $(STANDARD_SRC:.c=.o)

# BONUS #
BONUS_SRC	    = $(addprefix $(SRC_DIR)/, $(BONUS_MAIN))
BONUS_SRC	   += $(addprefix $(SRC_DIR)/, $(LEXER))
BONUS_SRC	   += $(addprefix $(SRC_DIR)/, $(PARSER))
BONUS_SRC	   += $(addprefix $(SRC_DIR)/, $(STACK))
BONUS_SRC	   += $(addprefix $(SRC_DIR)/, $(MOVEMENTS))
BONUS_SRC	   += $(addprefix $(SRC_DIR)/, $(ERROR))
BONUS_SRC	   += $(addprefix $(SRC_DIR)/, $(SORT))
BONUS_OBJ		= $(BONUS_SRC:.c=.o)

# TEST #
TEST_SRC			= $(addprefix $(SRC_DIR)/, $(LEXER))
TEST_SRC		   += $(addprefix $(SRC_DIR)/, $(PARSER))
TEST_SRC		   += $(addprefix $(SRC_DIR)/, $(STACK))
TEST_SRC		   += $(addprefix $(SRC_DIR)/, $(MOVEMENTS))
TEST_SRC		   += $(addprefix $(SRC_DIR)/, $(ERROR))
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
	@make all -s -C ./$(STR_ARR_DIR)/
	@$(CC) $(CFLAGS) $(STANDARD_OBJ) -L./$(LIB_DIR) ./$(LIB_DIR)/$(LIBFT) -L./$(STR_ARR_DIR) ./$(STR_ARR_DIR)/$(STRING_ARRAY) -o $(NAME)
	@echo "$(C_GREEN)$(CAP_NAME) built and ready to go!$(C_DEF)"

clean:
	@$(RM) */*.o */*/*.o
	@make clean -s -C $(LIB_DIR)
	@make clean -s -C $(STR_ARR_DIR)
	@echo "$(C_RED)Cleaned objects!$(C_DEF)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@$(RM) $(TEST_NAME)
	@make fclean -s -C $(LIB_DIR)
	@make fclean -s -C $(STR_ARR_DIR)
	@echo "$(C_RED)Cleaned $(NAME) program!$(C_DEF)"

re: fclean all

bonus: $(BONUS_OBJ)
	@echo "$(C_BLUE)Builing $(NAME) with bonus...$(C_DEF)"
	@make all -s -C ./$(LIB_DIR)/
	@make all -s -C ./$(STR_ARR_DIR)/
	@$(CC) $(CFLAGS) $(BONUS_OBJ) -L./$(LIB_DIR) ./$(LIB_DIR)/$(LIBFT) -L./$(STR_ARR_DIR) ./$(STR_ARR_DIR)/$(STRING_ARRAY) -o checker
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
