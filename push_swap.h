/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:54:27 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/02 16:22:38 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// ========== Libraries ========== //
# include <stdlib.h>
# include <stddef.h>

// ========== Headers ============ //
# include "src/data/data.h"
# include "src/parser/parser.h"
# include "src/moves/moves.h"
# include "src/algorithm/algorithm.h"
# include "src/libft/libft.h"
# include "src/ft_printf/ft_printf.h"

// ========= Definitions ========= //
# ifndef BOOLEANS
#  define TRUE  1
#  define FALSE 0
# endif
# ifndef ERRORS
#  define ERROR  -1
# endif

int		main(int argc, char **argv);

#endif
