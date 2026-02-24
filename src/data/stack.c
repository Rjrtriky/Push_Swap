/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:54 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/02/24 01:14:33 by rjuarez-         ###   ########.fr       */
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

	if (stack == NULL)
		return (1);
	del_node = ft_stack_pop(stack);
	while (del_node != NULL)
	{
		ft_node_free(del_node);
		del_node = ft_stack_pop(stack);
	}
	free(stack);
	return (0);
}
