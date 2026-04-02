/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:49:05 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/02 17:09:18 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void	ft_stack_a_only_3(t_data *data);
void	ft_sort_3(t_data *data);

void	ft_stack_a_only_3(t_data *data)
{
	t_stack	*stack_a;

	if ((data == NULL) || (data->stack_a == NULL))
		return ;
	stack_a = data->stack_a;
	while (stack_a->size > 3)
		pb(data);
	if (stack_a->size == 3)
		ft_sort_3(data);
	ft_stack_index_ord(stack_a);
}

void	ft_sort_3(t_data *data)
{
	int	num1;
	int	num2;
	int	num3;

	if (data == NULL || data->stack_a == NULL || data->stack_a->size != 3)
		return ;
	num1 = data->stack_a->first_node->num;
	num2 = data->stack_a->first_node->next->num;
	num3 = data->stack_a->end_node->num;
	if ((num1 > num2) && (num2 < num3) && (num1 < num3))
		sa(data);
	else if ((num1 > num2) && (num2 > num3))
	{
		sa(data);
		rra(data);
	}
	else if ((num1 > num2) && (num2 < num3) && (num1 > num3))
		ra(data);
	else if ((num1 < num2) && (num2 > num3) && (num1 < num3))
	{
		sa(data);
		ra(data);
	}
	else if ((num1 < num2) && (num2 > num3) && (num1 > num3))
		rra(data);
}
