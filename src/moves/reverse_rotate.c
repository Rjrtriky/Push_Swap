/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 05:04:00 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/02 17:04:14 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
void	ft_reverse_rotate(t_stack *stack);

/*FT_REVERSE_ROTATE
 * @def Shifts down all elements of the stack by one position
 *
 * @param
 *      {t_stack*} stack - Stack to reverse rotate
 *
 * @returns {void}
 */
void	ft_reverse_rotate(t_stack *stack)
{
	t_node	*node;

	if (stack != NULL)
	{
		node = ft_stack_pop_last(stack);
		if (node != NULL)
			ft_stack_add(stack, node);
	}
}

/*RRA
 * @def Reverse rotate a: Shifts down all elements of stack a by one position
 *
 * @param
 *      {t_data*} data - Main structure containing stacks a and b
 *
 * @returns {void}
 */
void	rra(t_data *data)
{
	if ((data != NULL) && (data->stack_a != NULL) && (data->stack_a->size > 1))
	{
		ft_reverse_rotate(data->stack_a);
		ft_register("rra");
	}
}

/*RRB
 * @def Reverse rotate b: Shifts down all elements of stack b by one position
 *
 * @param
 *      {t_data*} data - Main structure containing stacks a and b
 *
 * @returns {void}
 */
void	rrb(t_data *data)
{
	if ((data != NULL) && (data->stack_b != NULL) && (data->stack_b->size > 1))
	{
		ft_reverse_rotate(data->stack_b);
		ft_register("rrb");
	}
}

/*RRR
 * @def Reverse rotate both: Executes rra and rrb simultaneously
 *
 * @param
 *      {t_data*} data - Main structure containing stacks a and b
 *
 * @returns {void}
 */
void	rrr(t_data *data)
{
	if ((data != NULL) && (data->stack_a != NULL) && (data->stack_b != NULL)
		&& (data->stack_a->size > 1) && (data->stack_b->size > 1))
	{
		ft_reverse_rotate(data->stack_a);
		ft_reverse_rotate(data->stack_b);
		ft_register("rrr");
	}
}
