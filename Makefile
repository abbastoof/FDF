# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 18:44:20 by atoof             #+#    #+#              #
#    Updated: 2023/05/06 15:49:06 by atoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC_DIR = ./src
SRC = colors.c draw.c ft_atoi_base.c iometric.c main.c \
      visualize.c default_settings.c error.c helper_functions.c \
      key_handler.c read_file.c zoom.c init_z_matrix.c
HEADER_DIR = ./include
HEADER = fdf.h
OBJ_DIR = ./obj
OBJ = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))
LIBFT = ./libft/libft.a
FLAGS = -Wall -Werror -Wextra
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	KEY = -lmlx -framework OpenGL -framework AppKit
else
	KEY = -lmlx -lX11 -lXext -lm
endif
# ANSI escape sequences for text formatting
BOLD = \033[1m
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[0;36m
NC = \033[0m

vpath %.c $(SRC_DIR)
vpath %.h $(HEADER_DIR)

all: organize_files $(NAME)

organize_files:
	@if [ ! -d $(SRC_DIR) ] || [ ! -d $(HEADER_DIR) ] || [ ! -d $(OBJ_DIR) ]; then \
		echo "$(YELLOW)$(BOLD)Organizing files...$(NC)"; \
		mkdir -p $(SRC_DIR) $(HEADER_DIR) $(OBJ_DIR); \
		find . -maxdepth 1 -type f -iname "*.c" -exec mv {} $(SRC_DIR) \; -exec touch {} \;; \
		find . -maxdepth 1 -type f -iname "*.h" -exec mv {} $(HEADER_DIR) \;; \
		find . -maxdepth 1 -type f -empty -delete; \
	else \
		echo "$(YELLOW)$(BOLD)$(NAME) is already up-to-date!$(NC)"; \
	fi

$(NAME): $(OBJ)
	@if [ -f $(NAME) ] && [ "$(OBJ)" -ot "$(NAME)" ]; then \
		echo "$(GREEN)$(BOLD)$(NAME) is already up-to-date!$(NC)"; \
	else \
		echo "$(YELLOW)$(BOLD)Compiling $(NAME)...$(NC)"; \
		make -C ./libft; \
		cc $(FLAGS) $(OBJ) -I$(HEADER_DIR) $(LIBFT) $(KEY) -o $@; \
		echo "$(GREEN)$(BOLD)$(NAME) successfully compiled!$(NC)"; \
	fi

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@cc $(FLAGS) -I$(HEADER_DIR) -c $< -o $@
	@echo "$(YELLOW)$(BOLD)Compiled $<$(NC)"

clean:
	@echo "$(CYAN)$(BOLD)Cleaning object files...$(NC)"
	@make clean -C ./libft
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "$(CYAN)$(BOLD)Cleaning $(NAME)...$(NC)"
	@make fclean -C ./libft
	@/bin/rm -f $(NAME)
	@echo "$(GREEN)$(BOLD)$(NAME) successfully cleaned!$(NC)"

re: fclean all

