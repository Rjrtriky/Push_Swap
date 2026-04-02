/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 20:29:25 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/02 17:00:04 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../data/data.h"
# include "../libft/libft.h"

// ========= Definitions ========= //
# ifndef BOOLEANS
#  define TRUE  1
#  define FALSE 0
# endif
# ifndef ERRORS
#  define ERROR  -1
# endif

// parser.c
t_data		*ft_parse_and_load(int argc, char **argv);

// split_args.c
void		ft_free_split(char **tokens);
char		**ft_split_args(char *str);

// validate.c
int	ft_is_valid_token(char *str);
int	ft_is_duplicate(t_stack *stack, int value);
int	ft_validate_input_number(t_data *data, char *str, int *num);

#endif