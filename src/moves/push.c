/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 05:03:19 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/02/24 18:30:17 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "moves.h"

/*
pa (empujar a): Toma el primer elemento de la parte superior de b y colócalo en
la parte superior de a.
No haces nada si b está vacío. 
pb (empujar b): Toma el primer elemento en la parte superior de a y colócalo en
la parte superior de b.
No hacer nada si a está vacío.*/

/*void	pa(t_data *data);
void	pb(t_data *data);
void	ft_push(t_stack *stack_ori, t_stack *stack_des);*/

/*FT_PUSH
 * @def Pops a node from origin stack and pushes it to destination stack
 *
 * @param
 *      {t_stack*} stack_ori - Origin stack to pop from
 *      {t_stack*} stack_des - Destination stack to push to
 *
 * @returns {void}
 */
void	ft_push(t_stack *stack_ori, t_stack *stack_des)
{
	t_node	*node;

	if (stack_ori != NULL)
	{
		node = ft_stack_pop(stack_ori);
		if (node != NULL)
			ft_stack_add(stack_des, node);
	}
}

/*PA
 * @def Push a: Takes the first element from stack b and puts it on top of
 * stack a
 *
 * @param
 *      {t_data*} data - Main structure containing stacks a and b
 *
 * @returns {void}
 */
void	pa(t_data *data)
{
	ft_push(data->stack_b, data->stack_a);
	ft_register ("pa");
}

/*PB
 * @def Push b: Takes the first element from stack a and puts it on top of
 * stack b
 *
 * @param
 *      {t_data*} data - Main structure containing stacks a and b
 *
 * @returns {void}
 */
void	pb(t_data *data)
{
	ft_push(data->stack_a, data->stack_b);
	ft_register ("pb");
}
