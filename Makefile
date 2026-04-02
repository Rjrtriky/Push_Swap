# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/24 23:37:27 by rjuarez-          #+#    #+#              #
#    Updated: 2026/04/02 17:30:48 by rjuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==============================================================================
#	SETTINGS
# ============================================================================== 
NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

# ==============================================================================
#   PATHS
# ==============================================================================
SRCS_DIR		= src
DATA_DIR		= $(SRCS_DIR)/data/
PARSER_DIR		= $(SRCS_DIR)/parser/
MOVES_DIR		= $(SRCS_DIR)/moves/
ALGORITHM_DIR	= $(SRCS_DIR)/algorithm/
LIBFT_DIR		= $(SRCS_DIR)/libft/
FT_PRINTF_DIR	= $(SRCS_DIR)/ft_printf/

# ==============================================================================
#   HEADERS
# ==============================================================================
HEADERS =	push_swap.h \
			$(DATA_DIR)/data.h \
			$(PARSER_DIR)/parser.h \
			$(MOVES_DIR)/moves.h \
			$(ALGORITHM_DIR)/algorithm.h \
			$(LIBFT_DIR)/libft.h \
			$(FT_PRINTF_DIR)/ft_printf.h

# ==============================================================================
#	SOURCES
# ==============================================================================
DATA_FILES		= node.c stack.c stack_utils.c data.c 
PARSER_FILES	= parser.c split_args.c validate.c
MOVES_FILES		= push.c swap.c rotate.c reverse_rotate.c moves_utils.c
ALGORITHM_FILES = algorithm.c first_step.c target.c cost.c execute_best_move.c
LIBFT_FILES		= $(notdir $(wildcard $(LIBFT_DIR)/*.c))
FT_PRINTF_FILES = ft_printf.c ft_conver_numbers.c  ft_puts.c ft_conver.c

PUSH_SWAP		= push_swap.c

# ==============================================================================
#   FULL PATH SOURCES
# ==============================================================================
DATA		= $(addprefix $(DATA_DIR), $(DATA_FILES))
MOVES		= $(addprefix $(MOVES_DIR), $(MOVES_FILES))
PARSER		= $(addprefix $(PARSER_DIR), $(PARSER_FILES))
ALGORITHM	= $(addprefix $(ALGORITHM_DIR), $(ALGORITHM_FILES))
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_FILES))
FT_PRINTF	= $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_FILES))

SRC			= $(DATA) $(PARSER) $(MOVES) $(ALGORITHM) $(LIBFT) $(FT_PRINTF) \
			  $(PUSH_SWAP)
			  
OBJ = $(SRC:.c=.o)

# ==============================================================================
#	RULES
# ==============================================================================
#	Default (Only "make")
#	Object Compilation
#		%  - wildcard
#		@  - echo off
#		$@ - output file (.o)
#		$< - input file (.c)
#
#	Cleaning rules
#		clean  - objects files
#		fclean - objects files and librery
#		re     - compile everything again

all: $(NAME)

#	Build executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "✅ Executable $(NAME) created!"

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "🔨 Compiling $<"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
