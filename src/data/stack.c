/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:54 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/03/31 22:12:04 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

/*
typedef struct s_stack
{
	struct t_node	*first_node;
	struct t_node	*end_node;
	int				size;
}		t_stack;
*/

// -------- Builders Stack ----------- //
t_stack	*ft_stack_new(void);
// -------- Erased Stack ------------- //
int		ft_stack_free(t_stack *stack);
// -------- Actions Data ------------- //
void	ft_stack_index_ord(t_stack *stack);
int		ft_stack_add(t_stack *stack, t_node *node);
t_node	*ft_stack_pop(t_stack *stack);

/*FT_STACK_NEW
 * @def Creates and initializes a new t_stack structure
 *
 * @param void
 *
 * @returns {t_stack*}
 *      OK - Pointer to the new initialized t_stack structure
 *      KO - NULL if memory allocation fails
 */
t_stack	*ft_stack_new(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->first_node = NULL;
	new->end_node = NULL;
	new->size = 0;
	return (new);
}

/*FT_STACK_FREE
 * @def Frees the memory of the stack and all its nodes
 *
 * @param
 *      {t_stack*} stack - Pointer to the stack to free
 *
 * @returns {int}
 *      OK - 0 if successfully freed
 *      KO - 1 if stack is NULL
 */
int	ft_stack_free(t_stack *stack)
{
	t_node	*del_node;

	del_node = ft_stack_pop(stack);
	while (del_node != NULL)
	{
		ft_node_free(del_node);
		del_node = ft_stack_pop(stack);
	}
	free(stack);
	return (TRUE);
}

/*FT_STACK_INDEX
 * @def Assigns sequential indices to all nodes in the stack
 *
 * @param
 *      {t_stack*} stack - Stack to index
 *
 * @returns {void}
 */
void	ft_stack_index_ord(t_stack *stack)
{
	int		i;
	t_node	*node;
	t_node	*node_min;

	if (stack == NULL || stack->size == 0 || stack->first_node == NULL)
		return ;
	ft_stack_index_clear(stack);
	i = 1;
	while (i <= stack->size)
	{
		node = stack->first_node;
		node_min = NULL;
		while (node != NULL)
		{
			if ((node->index == 0) && ((node_min == NULL)
					|| (node->num < node_min->num)))
				node_min = node;
			node = node->next;
		}
		node_min->index = i;
		i++;
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
		node->next = stack->first_node;
		stack->first_node->previous = node;
		stack->first_node = node;
	}
	stack->size++;
	return (TRUE);
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
	node->next = NULL;
	node->previous = NULL;
	return (node);
}
