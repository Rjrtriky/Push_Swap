/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:29:54 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/02 17:07:52 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "../data/data.h"
# include "../moves/moves.h"
# include "../libft/libft.h"

// algorithm.c
void	ft_rotate_sort(t_data *data);
void	ft_cost_based_algorithm(t_data *data);
// first_step.c
void	ft_stack_a_only_3(t_data *data);
void	ft_sort_3(t_data *data);
// target.c
void	ft_find_node_target(t_stack *stack_a, t_node *node_b);
void	ft_assign_targets_stack_b(t_data *data);
// cost.c
int		ft_get_node_position_in_stack(t_stack *stack, t_node *node);
void	ft_calculate_cost_b(t_stack *stack_b, t_node *node_b);
void	ft_calculate_cost_a(t_stack *stack_a, t_node *node_b);
void	ft_calculate_costs(t_data *data);
// execute_best_move.c
t_node	*ft_find_best_node(t_stack *stack_b);
void	ft_rotate_stack_a(t_data *data, int *cost_a);
void	ft_rotate_stack_b(t_data *data, int *cost_b);
void	ft_rotate_stacks_for_node(t_data *data, t_node *best_node);
void	ft_execute_best_move(t_data *data);

#endif