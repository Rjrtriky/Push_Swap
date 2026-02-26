/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:22:43 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/02/24 18:17:08 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "debug.h"
#include <stddef.h>
#include <stdlib.h>

void	ft_stack_index(t_stack *stack);
int		ft_stack_add(t_stack *stack, t_node *node);
int		ft_stack_add_end(t_stack *stack, t_node *node);
t_node	*ft_stack_pop(t_stack *stack);
t_node	*ft_stack_pop_end(t_stack *stack);

/*FT_STACK_INDEX
 * @def Assigns sequential indices to all nodes in the stack
 *
 * @param
 *      {t_stack*} stack - Stack to index
 *
 * @returns {void}
 */
void	ft_stack_index(t_stack *stack)
{
	int		i;
	t_node	*node;

	if (stack != NULL)
	{
		node = stack->first_node;
		i = 0;
		while (node != NULL)
		{
			node->index = i;
			i++;
			node = node->next;
		}
		stack->size = i;
	}
}

/*FT_STACK_ADD
 * @def Adds a node to the beginning of the stack
 *
 * @param
 *      {t_stack*} stack - Stack where to add the node
 *      {t_node*} node - Node to add
 *
 * @returns {int}
 *      OK - 0 if successfully added
 *      KO - 1 if stack or node is NULL
 */
int	ft_stack_add(t_stack *stack, t_node *node)
{
	if ((stack == NULL) || (node == NULL))
		return (1);
	node->next = NULL;
	node->previous = NULL;
	if (stack->first_node == NULL)
	{
		stack->first_node = node;
		stack->end_node = node;
	}
	else
	{
		node->next = stack->first_node;
		stack->first_node->previous = node;
		stack->first_node = node;
	}
	stack->size++;
	return (0);
}

/*FT_STACK_ADD_END
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
int	ft_stack_add_end(t_stack *stack, t_node *node)
{
	if ((stack == NULL) || (node == NULL))
		return (1);
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
	return (0);
}

/*FT_STACK_POP
 * @def Extracts and returns the first node of the stack
 *
 * @param
 *      {t_stack*} stack - Stack from which to extract the node
 *
 * @returns {t_node*}
 *      OK - Pointer to the extracted node
 *      KO - NULL if stack is NULL or empty
 */
t_node	*ft_stack_pop(t_stack *stack)
{
	t_node	*node;

	if (stack == NULL || stack->first_node == NULL)
		return (NULL);
	node = stack->first_node;
	stack->first_node = node->next;
	if (stack->first_node != NULL)
		stack->first_node->previous = NULL;
	else
		stack->end_node = NULL;
	stack->size--;
	ft_stack_index(stack);
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

/*FT_STACK_POP_END
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
	ft_stack_index(stack);
	node->next = NULL;
	node->previous = NULL;
	return (node);
}
