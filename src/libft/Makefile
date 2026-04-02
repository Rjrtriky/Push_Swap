# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/01 11:37:27 by rjuarez-          #+#    #+#              #
#    Updated: 2026/03/31 23:58:45 by rjuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# ==============================================================================
#	CATEGORIES
# ==============================================================================
STRINGS	= ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_strnstr.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c
PRINT	= ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
TESTING	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c
CONVER	= ft_itoa.c ft_toupper.c ft_tolower.c ft_atoi.c
MEMORY	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
		ft_memcmp.c ft_calloc.c ft_strdup.c
LIST	= ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
		ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
NUMBER	= ft_abs.c ft_atol.c

# ==============================================================================
#	GROUPS
# ==============================================================================

ALL	= $(STRINGS) $(PRINT) $(TESTING) $(CONVER) $(MEMORY) $(NUMBER)
BONUS = $(LIST)
INCLUDE = libft.h

# ==============================================================================
#	COMPILER CONFIGURATION
# ============================================================================== 
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# ==============================================================================
#	FILE CONVERSION
# ==============================================================================
OBJS = $(ALL:.c=.o)
OBJS_BONUS = $(BONUS:.c=.o)

# ==============================================================================
#	LIBRARY CREATION
# ==============================================================================
${NAME}: ${OBJS}
	${CC} ${CFLAGS} -c ${ALL}
	@ar crs ${NAME} ${OBJS}

bonus: $(OBJS) $(OBJS_BONUS)
	@ar crs ${NAME} ${OBJS_BONUS}

# ==============================================================================
#	RULES
# ==============================================================================
#	Default (Only "make")
all: ${NAME}

#	Object Compilation
#		%  - wildcard
#		@  - echo off
#		$@ - output file (.o)
#		$< - input file (.c)
%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

#	Cleaning rules
#		clean  - objects files
#		fclean - objects files and librery
#		re     - compile everything again
clean:
	rm -f ${OBJS} ${OBJS_BONUS}

fclean: clean
	rm -f $(NAME)

re: fclean all

# Avoid conflicts
.PHONY: all bonus clean fclean re 
