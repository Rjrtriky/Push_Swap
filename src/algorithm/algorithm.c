/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 00:59:11 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/02 18:15:12 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void	ft_rotate_sort(t_data *data);
void	ft_cost_based_algorithm(t_data *data);

/* FT_ROTATE_SORT
 * @def Rotates stack A until the element with index 1 (the smallest)
 *		is at the top of the stack
 * @param
 * 	{t_data*} data - Main structure containing stack A
 * @returns
 *		OK - void (no return value)
 *		KO - void (no return value)
 * @cond
 *		- data cannot be NULL
 *		- stack_a cannot be NULL
 *		- stack_a->first_node cannot be NULL
 *		- Node indices must be up to date
 * */
void	ft_rotate_sort(t_data *data)
{
	t_node	*node;
	int		pos;

	if ((data == NULL) || (data->stack_a == NULL) || (
			data->stack_a->first_node == NULL))
		return ;
	pos = 0;
	node = data->stack_a->first_node;
	while (node->index != 1)
	{
		node = node->next;
		pos++;
	}
	if (pos > (data->stack_a->size / 2))
	{
		while (data->stack_a->first_node->index != 1)
			rra(data);
	}
	else
	{
		while (data->stack_a->first_node->index != 1)
			ra(data);
	}
}

/* FT_COST_BASED_ALGORITHM
 * @def Main sorting algorithm that uses cost calculation to move elements
 *		between stacks A and B until the entire stack is sorted
 * @param
 * 	{t_data*} data - Main structure containing stacks A and B
 * @returns
 *		OK - void (no return value)
 *		KO - void (no return value)
 * @cond
 *		- data cannot be NULL
 *		- stack_a and stack_b must be initialized
 *		- stack_a must contain at least 3 elements at start
 * */
void	ft_cost_based_algorithm(t_data *data)
{
	ft_stack_a_only_3(data);
	ft_sort_3(data);
	while (data->stack_b->size > 0)
	{
		ft_data_index(data);
		ft_assign_targets_stack_b(data);
		ft_calculate_costs(data);
		ft_execute_best_move(data);
	}
	ft_stack_index_ord(data->stack_a);
	ft_rotate_sort(data);
}
