/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 05:03:45 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/02/24 02:20:11 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "moves.h"

/*ra (rotar a): Desplaza todos los elementos de la pila a en 1 posición.
El primer elemento se convierte en el último.
rb (rotar b): Desplaza todos los elementos de la pila b en 1 posición.
El primer elemento se convierte en el último.
rr: ra y rb simultáneamente.*/

void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	ft_rotate(t_stack *stack);

/*FT_ROTATE
 * @def Shifts up all elements of the stack by one position
 *
 * @param
 *      {t_stack*} stack - Stack to rotate
 *
 * @returns {void}
 */
void	ft_rotate(t_stack *stack)
{
	t_node	*node;

	if (stack != NULL)
	{
		node = ft_stack_pop(stack);
		if (node != NULL)
			ft_stack_add_end(stack, node);
	}
}

/*RA
 * @def Rotate a: Shifts up all elements of stack a by one position
 *
 * @param
 *      {t_data*} data - Main structure containing stacks a and b
 *
 * @returns {void}
 */
void	ra(t_data *data)
{
	if ((data != NULL) && (data->stack_a != NULL))
	{
		ft_rotate(data->stack_a);
		ft_register("ra");
	}
}

/*RB
 * @def Rotate b: Shifts up all elements of stack b by one position
 *
 * @param
 *      {t_data*} data - Main structure containing stacks a and b
 *
 * @returns {void}
 */
void	rb(t_data *data)
{
	if ((data != NULL) && (data->stack_b != NULL))
	{
		ft_rotate(data->stack_b);
		ft_register("rb");
	}
}

/*RR
 * @def Rotate both: Executes ra and rb simultaneously
 *
 * @param
 *      {t_data*} data - Main structure containing stacks a and b
 *
 * @returns {void}
 */
void	rr(t_data *data)
{
	if ((data != NULL) && (data->stack_a != NULL) && (data->stack_b != NULL))
	{
		ft_rotate(data->stack_a);
		ft_rotate(data->stack_b);
		ft_register("rr");
	}
}
