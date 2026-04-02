/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 20:31:18 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/01 21:41:46 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_is_valid_token(char *str);
int	ft_is_duplicate(t_stack *stack, int value);
int	ft_validate_input_number(t_data *data, char *str, int *num);

int	ft_is_valid_token(char *str)
{
	int	i;

	if ((str ==NULL) || (str[0] == '\0'))
		return (FALSE);
	i = 0;
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	if (str[i] == '\0')
		return (FALSE);
	while (str[i] != '\0')
	{
		if (ft_isdigit((int) str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	ft_is_duplicate(t_stack *stack, int value)
{
	t_node	*node;

	node = stack->first_node;
	while (node != NULL)
	{
		if (node->num == value)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}

int	ft_validate_input_number(t_data *data, char *str, int *num)
{
	long	value;

	if (ft_is_valid_token(str) == FALSE)
		return (TRUE);
	value = ft_atol(str);
	if (value < INT_MIN || value > INT_MAX)
		return (TRUE);
	if (ft_is_duplicate(data->stack_a, (int)value) == TRUE)
		return (TRUE);
	(*num) = (int) value;
	return (FALSE);
}

