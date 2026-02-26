/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:17:22 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/02/24 18:16:41 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "debug.h"
/*
typedef struct s_data
{
	struct t_stack	*stack_a;
	struct t_stack	*stack_b;
	int				n_nodes;
}		t_data;
*/

// -------- Builders Data ------------ //
t_data	*ft_data_new(void);
// -------- Erased Data -------------- //
int		ft_data_free(t_data *data);
// -------- Actions Data ------------- //
int		ft_data_stack_a_add(t_data *data, int nbr);
int		ft_data_stack_b_add(t_data *data, int nbr);

/*FT_DATA_NEW
 * @def Creates and initializes a new t_data structure
 *
 * @param void
 *
 * @returns {t_data*}
 *      OK - Pointer to the new initialized t_data structure
 *      KO - NULL if memory allocation fails
 */
t_data	*ft_data_new(void)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	if (new == NULL)
		return (NULL);
	new->stack_a = NULL;
	new->stack_b = NULL;
	new->n_nodes = 0;
	return (new);
}

/*FT_DATA_FREE
 * @def Frees the memory of the t_data structure and its stacks
 *
 * @param
 *      {t_data*} data - Pointer to the structure to free
 *
 * @returns {int}
 *      OK - 0 if successfully freed
 *      KO - 1 if data is NULL
 */
int	ft_data_free(t_data *data)
{
	if (!data)
		return (1);
	if (data->stack_a)
		ft_stack_free(data->stack_a);
	if (data->stack_b)
		ft_stack_free(data->stack_b);
	data->n_nodes = 0;
	free (data);
	return (0);
}

/*FT_DATA_STACK_A_ADD
 * @def Creates a new node with the given number and adds it to the beginning
 * 		of stack a
 *
 * @param
 *      {t_data*} data - Main structure containing stack a
 *      {int} nbr - Number to store in the new node
 *
 * @returns {int}
 *      OK - 0 if node was successfully created and added to stack a
 *      KO - 1 if data is NULL, stack creation fails, node creation fails,
 * 			or add operation fails
 */
int	ft_data_stack_a_add(t_data *data, int nbr)
{
	t_node	*new;

	if (data == NULL)
		return (1);
	if (data->stack_a == NULL)
		data->stack_a = ft_stack_new();
	if (data->stack_a == NULL)
		return (1);
	new = ft_node_new(nbr);
	if (new == NULL)
		return (1);
	if (ft_stack_add(data->stack_a, new) == 1)
		return (1);
	data->n_nodes++;
	return (0);
}

/*FT_DATA_STACK_B_ADD
 * @def Creates a new node with the given number and adds it to the beginning
 * 		of stack b
 *
 * @param
 *      {t_data*} data - Main structure containing stack b
 *      {int} nbr - Number to store in the new node
 *
 * @returns {int}
 *      OK - 0 if node was successfully created and added to stack b
 *      KO - 1 if data is NULL, stack creation fails, node creation fails,
 * 			 or add operation fails
 */
int	ft_data_stack_b_add(t_data *data, int nbr)
{
	t_node	*new;

	if (data == NULL)
		return (1);
	if (data->stack_b == NULL)
		data->stack_b = ft_stack_new();
	if (data->stack_b == NULL)
		return (1);
	new = ft_node_new(nbr);
	if (new == NULL)
		return (1);
	if (ft_stack_add(data->stack_b, new) == 1)
		return (1);
	data->n_nodes++;
	return (0);
}
