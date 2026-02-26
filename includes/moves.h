/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 03:37:15 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/02/24 18:32:14 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H
// ========== Libraries ========== //
# include "data.h"
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

// ======= Function Prototypes ======= //
// -------------- SWAP --------------- //
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	ft_swap(t_stack *stack);
// -------------- PUSH -------------- //
void	pa(t_data *data);
void	pb(t_data *data);
void	ft_push(t_stack *stack_ori, t_stack *stack_des);
// --------------ROTATE ------------- //
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	ft_rotate(t_stack *stack);
// --------- REVERSE ROTATE --------- //
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
void	ft_reverse_rotate(t_stack *stack);
// --------- UTILITES --------------- //
void	ft_register(char *mov);
#endif
