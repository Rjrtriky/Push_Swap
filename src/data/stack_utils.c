/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:22:43 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/03/31 22:12:57 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <stddef.h>
#include <stdlib.h>

int		ft_stack_add_last(t_stack *stack, t_node *node);
t_node	*ft_stack_pop_last(t_stack *stack);
void	ft_stack_index_clear(t_stack *stack);
int		ft_is_sort_stack(t_stack *stack);

/*FT_STACK_ADD_LAST
 * @def Adds a node to the end of the stack
 *
 * @param
 *      {t_stack*} stack - Stack where to add the node
 *      {t_node*} node - Node to add
 *
 * @returns {int}
 *      OK - 0 if successfully added
 *      KO - 1 if stack or node is NULL
 */
int	ft_stack_add_last(t_stack *stack, t_node *node)
{
	if ((stack == NULL) || (node == NULL))
		return (FALSE);
	node->next = NULL;
	node->previous = NULL;
	if (stack->first_node == NULL)
	{
		stack->first_node = node;
		stack->end_node = node;
	}
	else
	{
		node->previous = stack->end_node;
		stack->end_node->next = node;
		stack->end_node = node;
	}
	stack->size++;
	return (TRUE);
}

/*FT_STACK_POP_LAST
 * @def Extracts and returns the last node of the stack
 *
 * @param
 *      {t_stack*} stack - Stack from which to extract the node
 *
 * @returns {t_node*}
 *      OK - Pointer to the extracted node
 *      KO - NULL if stack is NULL or empty
 */
t_node	*ft_stack_pop_last(t_stack *stack)
{
	t_node	*node;

	if (stack == NULL || stack->end_node == NULL)
		return (NULL);
	node = stack->end_node;
	stack->end_node = node->previous;
	if (stack->end_node != NULL)
		stack->end_node->next = NULL;
	else
		stack->first_node = NULL;
	stack->size--;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

void	ft_stack_index_clear(t_stack *stack)
{
	t_node	*node;

	if (stack == NULL || stack->end_node == NULL)
		return ;
	node = stack->first_node;
	while (node != NULL)
	{
		node->index = 0;
		node = node->next;
	}
}

int	ft_is_sort_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*node_after;

	if ((stack == NULL) || (stack->first_node == NULL) || (stack->size == 1))
		return (TRUE);
	node = stack->first_node;
	while (node->index != 1)
		node = node->next;
	node_after = node->next;
	if (node->next == NULL)
		node_after = stack->first_node;
	while (node_after->index != 1)
	{
		if (node_after->num < node->num)
			return (FALSE);
		node = node_after;
		if (node->next == NULL)
			node_after = stack->first_node;
		else
			node_after = node->next;
	}
	return (TRUE);
}
