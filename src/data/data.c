/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:17:22 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/02/23 22:51:19 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
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
		f_stack_free(data->stack_a);
	if (data->stack_b)
		f_stack_free(data->stack_b);
	data->n_nodes = 0;
	free (data);
	return (0);
}
