/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 05:02:44 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/02/24 01:13:53 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*sa (intercambiar a): Intercambia los dos primeros elementos de la parte
superior de la pila a.
No haces nada si solo hay un elemento o no hay ninguno.
sb (intercambiar b): Intercambia los dos primeros elementos de la parte 
superior de la pila b.
No haces nada si solo hay un elemento o no hay ninguno.
ss: sa y sb simultáneamente.*/

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	ft_swap(t_stack *stack);

/*FT_SWAP
 * @def Swaps the first two elements of the stack
 *
 * @param
 *      {t_stack*} stack - Stack whose first two elements will be swapped
 *
 * @returns {void}
 */
void	ft_swap(t_stack *stack)
{
	t_node	*node_1;
	t_node	*node_2;

	if ((stack != NULL) && (stack->size > 1))
	{
		node_1 = ft_stack_pop(stack);
		node_2 = ft_stack_pop(stack);
		ft_stack_add(stack, node_1);
		ft_stack_add(stack, node_2);
	}
}

/*SA
 * @def Swap a: Swaps the first two elements of stack a
 *
 * @param
 *      {t_data*} data - Main structure containing stacks a and b
 *
 * @returns {void}
 */
void	sa(t_data *data)
{
	if ((data != NULL) && (data->stack_a != NULL) && (data->stack_a->size > 1))
	{
		ft_swap(data->stack_a);
		ft_register("sa");
	}
}

/*SB
 * @def Swap b: Swaps the first two elements of stack b
 *
 * @param
 *      {t_data*} data - Main structure containing stacks a and b
 *
 * @returns {void}
 */
void	sb(t_data *data)
{
	if ((data != NULL) && (data->stack_b != NULL) && (data->stack_b->size > 1))
	{
		ft_swap(data->stack_b);
		ft_register("sb");
	}
}

/*SS
 * @def Swap both: Executes sa and sb simultaneously
 *
 * @param
 *      {t_data*} data - Main structure containing stacks a and b
 *
 * @returns {void}
 */
void	ss(t_data *data)
{
	if ((data != NULL) && (data->stack_a != NULL) && (data->stack_b != NULL)
		&& (data->stack_a->size > 1) && (data->stack_b->size > 1))
	{
		ft_swap(data->stack_a);
		ft_swap(data->stack_b);
		ft_register("ss");
	}
}
