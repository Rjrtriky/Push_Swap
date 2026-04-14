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

/* FT_IS_VALID_TOKEN
 * @def Checks if a token string represents a valid integer number
 * @param
 * 	{char*} str - Token to validate
 * @returns
 *		OK - TRUE (1) if token is a valid number format
 *		KO - FALSE (0) if token is invalid (empty, only sign, non-digits, etc.)
 * @cond
 *		- str cannot be NULL
 * */
int	ft_is_valid_token(char *str)
{
	int	i;

	if ((str == NULL) || (str[0] == '\0'))
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

/* FT_IS_DUPLICATE
 * @def Checks if a numeric value already exists in a stack
 * @param
 * 	{t_stack*} stack - Stack where to search for duplicates
 * 	{int} value - Value to check for duplicates
 * @returns
 *		OK - TRUE (1) if value already exists in the stack
 *		KO - FALSE (0) if value is not found in the stack
 * @cond
 *		- stack cannot be NULL
 * */
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

/* FT_VALIDATE_INPUT_NUMBER
 * @def Validates a number string and stores the converted value if valid
 * @param
 * 	{t_data*} data - Main structure containing stack A for duplicate check
 * 	{char*} str - String containing the number to validate
 * 	{int*} num - Pointer where to store the validated number
 * @returns
 *		OK - FALSE (0) if validation is successful
 *		KO - TRUE (1) if format invalid, out of range, or duplicate found
 * @cond
 *		- data cannot be NULL
 *		- str cannot be NULL
 *		- num cannot be NULL
 *		- data->stack_a must be initialized
 * */
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
