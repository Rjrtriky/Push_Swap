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

/*void	find_node_target(t_stack *stack_a, t_node *node_b)
pone en node_b->target un puntero al nodo inmediatemante mayor de la stack_A*/

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

/*void	assign_targets_stack_b(t_data *data) 
recorro cada nodo de stack_b poniendo en el nodo destino respecto a la stack_A*/

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

