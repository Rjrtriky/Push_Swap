/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_best_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 20:29:47 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/02 17:09:07 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

t_node	*ft_find_best_node(t_stack *stack_b);
void	ft_rotate_stack_a(t_data *data, int *cost_a);
void	ft_rotate_stack_b(t_data *data, int *cost_b);
void	ft_rotate_stacks_for_node(t_data *data, t_node *best_node);
void	ft_execute_best_move(t_data *data);

t_node	*ft_find_best_node(t_stack *stack_b)
{
	t_node	*best_node;
	t_node	*node;

	node = stack_b->first_node;
	best_node = node;
	while (node != NULL)
	{
		if (node->cost_total < best_node->cost_total)
			best_node = node;
		node = node->next;
	}
	return (best_node);
}

void	ft_rotate_stack_a(t_data *data, int *rotate_a)
{
	while (*rotate_a > 0)
	{
		ra(data);
		(*rotate_a)--;
	}
	while (*rotate_a < 0)
	{
		rra(data);
		(*rotate_a)++;
	}
}

void	ft_rotate_stack_b(t_data *data, int *rotate_b)
{
	while (*rotate_b > 0)
	{
		rb(data);
		(*rotate_b)--;
	}
	while (*rotate_b < 0)
	{
		rrb(data);
		(*rotate_b)++;
	}
}

void	ft_rotate_stacks_for_node(t_data *data, t_node *best_node)
{
	int	rotate_a;
	int	rotate_b;

	rotate_a = best_node->cost_rot_a;
	rotate_b = best_node->cost_rot_b;
	while ((rotate_a > 0) && (rotate_b > 0))
	{
		rr(data);
		rotate_a--;
		rotate_b--;
	}
	while ((rotate_a < 0) && (rotate_b < 0))
	{
		rrr(data);
		rotate_a++;
		rotate_b++;
	}
	ft_rotate_stack_a(data, &rotate_a);
	ft_rotate_stack_b(data, &rotate_b);
}

void	ft_execute_best_move(t_data *data)
{
	t_node	*best_node;

	best_node = ft_find_best_node(data->stack_b);
	ft_rotate_stacks_for_node(data, best_node);
	pa(data);
}
