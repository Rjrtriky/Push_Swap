/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:43:32 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/02 17:09:23 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void	ft_find_node_target(t_stack *stack_a, t_node *node_b);
void	ft_assign_targets_stack_b(t_data *data);

/* FT_FIND_NODE_TARGET
 * @def Finds the target node in stack A for a given node from stack B.
 *		The target is the node with the smallest larger value than node B,
 *		or the minimum if node B is larger than all
 * @param
 * 	{t_stack*} stack_a - Stack A where to search for the target
 * 	{t_node*} node_b - Node from stack B that needs a target
 * @returns
 *		OK - void (sets node_b->target)
 *		KO - void (does not set target if not found)
 * @cond
 *		- stack_a cannot be NULL
 *		- node_b cannot be NULL
 *		- stack_a must have at least one element
 * */
void	ft_find_node_target(t_stack *stack_a, t_node *node_b)
{
	t_node	*node_a;
	t_node	*node_best;

	node_a = stack_a->first_node;
	node_best = NULL;
	while (node_a != NULL)
	{
		if (node_a->num > node_b->num)
			if ((node_best == NULL) || (node_a->num < node_best->num))
				node_best = node_a;
		node_a = node_a->next;
	}
	if (node_best == NULL)
	{
		node_a = stack_a->first_node;
		node_best = stack_a->first_node;
		while (node_a != NULL)
		{
			if (node_a->num < node_best->num)
				node_best = node_a;
			node_a = node_a->next;
		}
	}
	node_b->target = node_best;
}

/* FT_ASSIGN_TARGETS_STACK_B
 * @def Assigns a target node to each node in stack B by traversing the
 *		entire stack and calling ft_find_node_target for each node
 * @param
 * 	{t_data*} data - Main structure containing stacks A and B
 * @returns
 *		OK - void (no return value)
 *		KO - void (no return value)
 * @cond
 *		- data cannot be NULL
 *		- stack_b cannot be NULL
 *		- stack_b must have at least one element
 *		- stack_a must have at least one element
 * */
void	ft_assign_targets_stack_b(t_data *data)
{
	t_node	*node_b;

	node_b = data->stack_b->first_node;
	while (node_b != NULL)
	{
		ft_find_node_target(data->stack_a, node_b);
		node_b = node_b->next;
	}
}
