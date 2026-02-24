/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:01:21 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/02/23 22:56:37 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

/*
typedef struct s_node
{
	struct t_node	*next;
	struct t_node	*previous;
	int				num;
	int				index;
	int				cost_rot_a;
	int				cost_rot_b;
	int				cost_total;
	struct s_node	*target;
}		t_node;
*/

// -------- Builders Node ------------ //
t_node	*ft_node_new(int nbr);
// -------- Erased Node -------------- //
int		ft_node_free(t_node *node);
// -------- Actions Node ------------- //

/*FT_NODE_NEW
 * @def Creates and initializes a new node with the given number
 *
 * @param
 *      {int} nbr - Number to store in the node
 *
 * @returns {t_node*}
 *      OK - Pointer to the new initialized node
 *      KO - NULL if memory allocation fails
 */
t_node	*ft_node_new(int nbr)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->num = nbr;
	new->next = NULL;
	new->previous = NULL;
	new->index = 0;
	new->target = NULL;
	new->cost_rot_a = 0;
	new->cost_rot_b = 0;
	new->cost_total = 0;
	return (new);
}

/*FT_NODE_FREE
 * @def Frees the memory of a node
 *
 * @param
 *      {t_node*} node - Node to free
 *
 * @returns {int}
 *      OK - 0 if successfully freed
 *      KO - 1 if node is NULL
 */
int	ft_node_free(t_node *node)
{
	if (node == NULL)
		return (1);
	free (node);
	return (0);
}
