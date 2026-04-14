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

/* FT_GET_NODE_POSITION_IN_STACK
 * @def Gets the position (index) of a specific node within a stack,
 *		counting from 0 (first_node = position 0)
 * @param
 * 	{t_stack*} stack - Stack where to search for the node
 * 	{t_node*} node_search - Node to locate
 * @returns
 *		OK - Position of the node (0 for first_node, 1 for next, etc.)
 *		KO - -1 if node is not found in the stack
 * @cond
 *		- stack cannot be NULL
 *		- node_search cannot be NULL
 *		- stack must have at least one element
 * */
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

/* FT_CALCULATE_COST_B
 * @def Calculates the rotation cost to bring a specific node from stack B
 *		to the top. Uses positive values for normal rotation (rb) and
 *		negative values for reverse rotation (rrb)
 * @param
 * 	{t_stack*} stack_b - Stack B containing the node
 * 	{t_node*} node_b - Node to evaluate
 * @returns
 *		OK - void (sets node_b->cost_rot_b)
 *		KO - void (does not set cost if error occurs)
 * @cond
 *		- stack_b cannot be NULL
 *		- node_b cannot be NULL
 *		- node_b must belong to stack_b
 * */
void	ft_calculate_cost_b(t_stack *stack_b, t_node *node_b)
{
	int	pos;

	pos = ft_get_node_position_in_stack(stack_b, node_b);
	if (pos <= (stack_b->size / 2))
		node_b->cost_rot_b = pos;
	else
		node_b->cost_rot_b = -1 * (stack_b->size - pos);
}

/* FT_CALCULATE_COST_A
 * @def Calculates the rotation cost to bring the target node of a B node
 *		to the top of stack A. Uses positive values for ra and negative for rra
 * @param
 * 	{t_stack*} stack_a - Stack A containing the target node
 * 	{t_node*} node_b - B node whose target will be rotated
 * @returns
 *		OK - void (sets node_b->cost_rot_a)
 *		KO - void (does not set cost if error occurs)
 * @cond
 *		- stack_a cannot be NULL
 *		- node_b cannot be NULL
 *		- node_b->target cannot be NULL
 *		- node_b->target must belong to stack_a
 * */
void	ft_calculate_cost_a(t_stack *stack_a, t_node *node_b)
{
	int	pos;

	pos = ft_get_node_position_in_stack(stack_a, node_b->target);
	if (pos <= (stack_a->size / 2))
		node_b->cost_rot_a = pos;
	else
		node_b->cost_rot_a = -1 * (stack_a->size - pos);
}

/* FT_CALCULATE_COSTS
 * @def Calculates the total cost to move each node from stack B to stack A.
 *		Optimizes by using simultaneous rotations when both costs have the
 *		same direction
 * @param
 * 	{t_data*} data - Main structure containing stacks A and B
 * @returns
 *		OK - void (sets node_b->cost_total for each node)
 *		KO - void (does not set costs if error occurs)
 * @cond
 *		- data cannot be NULL
 *		- stack_b cannot be NULL
 *		- stack_b must have at least one element
 *		- All nodes must have a target assigned
 * */
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
