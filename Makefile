# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/24 23:37:27 by rjuarez-          #+#    #+#              #
#    Updated: 2026/02/24 18:37:10 by rjuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==============================================================================
#   PATH INCLUDE
# ==============================================================================
SRCS_DIR	= ./src/
LIBFT_DIR	= ./libft/
INC_DIR		= ./includes/
DATA_DIR	= ./src/data/
MOVES_DIR	= ./src/moves/
UTILS_DIR	= ./src/utils/

# ==============================================================================
#   LIBRARY HEADERS
# ==============================================================================
HDRS =	$(INC_DIR)/data.h \
		$(INC_DIR)/moves.h \
		$(LIBFT_DIR)/libft.h \
		$(INC_DIR)/debug.h

# ==============================================================================
#	FILES
# ==============================================================================

LIBFT_FILES	= ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_strnstr.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_itoa.c ft_toupper.c ft_tolower.c ft_atoi.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
		ft_memcmp.c ft_calloc.c ft_strdup.c \
		ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
		ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
DATA_FILES	= data.c node.c stack.c utils.c
MOVES_FILES	= push.c reverse_rotate.c rotate.c swap.c moves_utils.c
# ALGORITHM	= 
# CORE	= 
# UTILS	= 
DEBUG_FILES	= debug.c
# ==============================================================================
#   FULL PATH
# ==============================================================================
LIBFT	= $(addprefix $(LIBFT_DIR)/, $(LIBFT_FILES))
DATA	= $(addprefix $(DATA_DIR), $(DATA_FILES))
MOVES	= $(addprefix $(MOVES_DIR), $(MOVES_FILES))
DEBUG	= $(addprefix $(UTILS_DIR), $(DEBUG_FILES))

# ==============================================================================
#	SOURCE FILES (without debug by default)
# ==============================================================================
ALL	= $(DATA) $(MOVES) $(LIBFT) $(DEBUG)
OBJS = $(ALL:.c=.o)

# ==============================================================================
#	COMPILER CONFIGURATION
# ============================================================================== 
NAME	= push_swap.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)
RM		= rm -rf

# ==============================================================================
#	LIBRARY CREATION
# ==============================================================================
${NAME}: ${OBJS}
	@ar crs ${NAME} ${OBJS}
	@echo "✅ Library $(NAME) created successfully!"

# ==============================================================================
#   OBJECT COMPILATION
# ==============================================================================
#	Object Compilation
#		%  - wildcard
#		@  - echo off
#		$@ - output file (.o)
#		$< - input file (.c)

%.o: %.c $(HDRS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🔨 Compiling: $<"

# ==============================================================================
#	RULES
# ==============================================================================
#	Default (Only "make")
all: ${NAME}

#	Cleaning rules
#		clean  - objects files
#		fclean - objects files and librery
#		re     - compile everything again
clean:
	rm -f ${OBJS}

fclean: clean
	rm -f $(NAME)

re: fclean all

check_headers:
	@for hdr in $(HDRS); do \
		if [ ! -f $$hdr ]; then \
			echo "❌ Error: Header $$hdr not found!"; \
			exit 1; \
		fi \
	done
	@echo "✅ All headers are present!"

structure:
	@echo "📁 Project structure:"
	@echo "  📂 Source files: $(words $(SRCS)) files"
	@echo "  📂 Debug files: $(words $(DEBUG)) files"
	@echo "  📂 Headers: $(words $(HDRS)) files"

# Avoid conflicts
.PHONY: all bonus clean fclean re 