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

/* FT_FIND_BEST_NODE
 * @def Traverses stack B and finds the node with the smallest total cost
 * @param
 * 	{t_stack*} stack_b - Stack B where to search for the best node
 * @returns
 *		OK - Pointer to the node with the smallest cost_total
 *		KO - NULL if stack is empty or NULL
 * @cond
 *		- stack_b cannot be NULL
 *		- stack_b must have at least one element
 *		- All nodes must have cost_total calculated
 * */
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

/* FT_ROTATE_STACK_A
 * @def Executes the necessary rotations on stack A according to the provided
 *      cost.
 *		Positive costs execute ra, negative costs execute rra
 * @param
 * 	{t_data*} data - Main structure containing stack A
 * 	{int*} cost_a - Pointer to rotation cost (modified during execution)
 * @returns
 *		OK - void (no return value)
 *		KO - void (no return value)
 * @cond
 *		- data cannot be NULL
 *		- stack_a cannot be NULL
 *		- cost_a cannot be NULL
 * */
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

/* FT_ROTATE_STACK_B
 * @def Executes the necessary rotations on stack B according to the provided 
 *      cost.
 *		Positive costs execute rb, negative costs execute rrb
 * @param
 * 	{t_data*} data - Main structure containing stack B
 * 	{int*} cost_b - Pointer to rotation cost (modified during execution)
 * @returns
 *		OK - void (no return value)
 *		KO - void (no return value)
 * @cond
 *		- data cannot be NULL
 *		- stack_b cannot be NULL
 *		- cost_b cannot be NULL
 * */
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

/* FT_ROTATE_STACKS_FOR_NODE
 * @def Rotates both stacks simultaneously to position a specific node from B
 *		and its target in A at the top. Optimizes using rr when both costs
 *		are positive and rrr when both are negative
 * @param
 * 	{t_data*} data - Main structure containing stacks A and B
 * 	{t_node*} best_node - Optimal node to move
 * @returns
 *		OK - void (no return value)
 *		KO - void (no return value)
 * @cond
 *		- data cannot be NULL
 *		- best_node cannot be NULL
 *		- stack_a and stack_b must exist
 *		- best_node must have cost_rot_a and cost_rot_b calculated
 * */
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

/* FT_EXECUTE_BEST_MOVE
 * @def Finds the node with the lowest total cost in stack B, rotates both stacks
 *		to position it correctly, and executes pa to move it to stack A
 * @param
 * 	{t_data*} data - Main structure containing stacks A and B
 * @returns
 *		OK - void (no return value)
 *		KO - void (no return value)
 * @cond
 *		- data cannot be NULL
 *		- stack_b cannot be empty
 *		- All nodes in B must have target and costs calculated
 * */
void	ft_execute_best_move(t_data *data)
{
	t_node	*best_node;

	best_node = ft_find_best_node(data->stack_b);
	ft_rotate_stacks_for_node(data, best_node);
	pa(data);
}
