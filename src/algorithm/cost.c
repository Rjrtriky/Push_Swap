/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:47:15 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/02 17:08:49 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

int		ft_get_node_position_in_stack(t_stack *stack, t_node *node);
void	ft_calculate_cost_b(t_stack *stack_b, t_node *node_b);
void	ft_calculate_cost_a(t_stack *stack_a, t_node *node_b);
void	ft_calculate_costs(t_data *data);

int	ft_get_node_position_in_stack(t_stack *stack, t_node *node_search)
{
	t_node	*node;
	int		pos;

	node = stack->first_node;
	pos = 0;
	while (node != NULL)
	{
		if (node_search == node)
			return (pos);
		node = node->next;
		pos++;
	}
	return (-1);
}


void	ft_calculate_cost_b(t_stack *stack_b, t_node *node_b)
{
	int	pos;

	pos = ft_get_node_position_in_stack(stack_b, node_b);
	if (pos <= (stack_b->size / 2))
		node_b->cost_rot_b = pos;
	else
		node_b->cost_rot_b = -1 * (stack_b->size - pos);
}


void	ft_calculate_cost_a(t_stack *stack_a, t_node *node_b)
{
	int	pos;

	pos = ft_get_node_position_in_stack(stack_a, node_b->target);
	if (pos <= (stack_a->size / 2))
		node_b->cost_rot_a = pos;
	else
		node_b->cost_rot_a = -1 * (stack_a->size - pos);
}


void	ft_calculate_costs(t_data *data)
{
	t_node	*node_b;
	int		cost_a;
	int		cost_b;

	node_b = data->stack_b->first_node;
	while (node_b != NULL)
	{
		ft_calculate_cost_a(data->stack_a, node_b);
		ft_calculate_cost_b(data->stack_b, node_b);
		cost_a = node_b->cost_rot_a;
		cost_b = node_b->cost_rot_b;
		if (((cost_a >= 0) && (cost_b >= 0)) || ((cost_a < 0) && (cost_b < 0)))
		{
			if (ft_abs(cost_a) > ft_abs(cost_b))
				node_b->cost_total = ft_abs(cost_a);
			else
				node_b->cost_total = ft_abs(cost_b);
		}
		else
			node_b->cost_total = ft_abs(cost_a) + ft_abs(cost_b);
		node_b = node_b->next;
	}
}
