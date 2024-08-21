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
OBJ_DIR			= objects
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

# NORMAL #
SRC_NAME		= lexer.c init.c error.c parser.c
SRC_MAIN		= main.c
OBJ_NAME		= $(notdir $(SRC_NAME:.c=.o))
OBJ_MAIN		= $(notdir $(SRC_MAIN:.c=.o))
OBJS			= $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))
MAIN_OBJ		= $(addprefix $(OBJ_DIR)/,$(OBJ_MAIN))

# BONUS #
BONUS_SRC_NAME	= 
BONUS_SRC_MAIN	= main_bonus.c
BONUS_OBJ_NAME	= $(notdir $(BONUS_SRC_NAME:.c=.o))
BONUS_OBJ_MAIN	= $(notdir $(BONUS_SRC_MAIN:.c=.o))
BONUS_OBJS		= $(addprefix $(OBJ_DIR)/,$(BONUS_OBJ_NAME))
BONUS_MAIN_OBJ	= $(addprefix $(OBJ_DIR)/,$(BONUS_OBJ_MAIN))

# TEST #
TEST_SRC		= test_runner.c
TEST_OBJ		= $(notdir $(TEST_SRC:.c=.o))
TEST_OBJS		= $(addprefix $(OBJ_DIR)/,$(TEST_OBJ))

# UNITY #
UNITY_SRC		= unity.c
UNITY_OBJ		= $(notdir $(UNITY_SRC:.c=.o))
UNITY_OBJS		= $(addprefix $(OBJ_DIR)/,$(UNITY_OBJ))


# COLORS #
C_GREEN			= \033[0;32m
C_RED			= \033[0;31m
C_BLUE			= \033[0;34m
C_DEF			= \033[0m


###############################################################################
# ====================== # Makefile done by mzurera- # ====================== #
###############################################################################


all: $(NAME)

$(OBJ_DIR)/test_runner.o: $(TEST_DIR)/test_runner.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -I $(INC_DIR) -I $(UNITY_DIR) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -I $(INC_DIR) -o $@

#$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
#	@mkdir -p $(INC_DIR)
#	@mkdir -p $(OBJ_DIR)
#	@$(CC) $(CFLAGS) -c $< -I $(INC_DIR) -I $(UNITY_DIR) -o $@

$(OBJ_DIR)/%.o: $(UNITY_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(NAME): $(OBJS) $(MAIN_OBJ)
	@echo "$(C_BLUE)Builing $(NAME)...$(C_DEF)"
	@make all -s -C ./$(LIB_DIR)/
	@$(CC) $(CFLAGS) $(OBJS) $(MAIN_OBJ) -L./$(LIB_DIR) ./$(LIB_DIR)/$(LIBFT) -o $(NAME)
	@echo "$(C_GREEN)$(CAP_NAME) built and ready to go!$(C_DEF)"

clean:
	@$(RM_DIR) $(OBJ_DIR)
	@make clean -s -C $(LIB_DIR)
	@echo "$(C_RED)Cleaned objects folder!$(C_DEF)"

fclean: clean
	@$(RM) $(NAME)O
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

test: $(OBJS) $(TEST_OBJS) $(UNITY_OBJS)
	@+make all -s -C ./$(LIB_DIR)/
	@$(CC) $(CFLAGS) $(OBJS) $(TEST_OBJS) $(UNITY_OBJS) -L./$(LIB_DIR) ./$(LIB_DIR)/$(LIBFT) -o $(TEST_NAME)
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