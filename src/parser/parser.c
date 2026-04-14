/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 20:30:38 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/01 22:59:58 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	ft_process_tokens(t_data *data, char **tokens);
static int	ft_process_argument(t_data *data, char *arg);
t_data		*ft_parse_and_load(int argc, char **argv);

/* FT_PROCESS_TOKENS
 * @def Processes an array of tokens (number strings) and loads them into stack A
 * @param
 * 	{t_data*} data - Main structure where to load the data
 * 	{char**} tokens - NULL-terminated array of token strings
 * @returns
 *		OK - FALSE (0) if all tokens were processed successfully
 *		KO - TRUE (1) if validation error or memory allocation fails
 * @cond
 *		- data cannot be NULL
 *		- tokens cannot be NULL
 *		- tokens must be NULL-terminated
 *		- Each token must be a valid number string
 * */
static int	ft_process_tokens(t_data *data, char **tokens)
{
	int	i;
	int	num;

	i = 0;
	while (tokens[i] != NULL)
	{
		if (ft_validate_input_number(data, tokens[i], &num) == TRUE)
			return (TRUE);
		if (ft_data_stack_a_add(data, num) == FALSE)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

/* FT_PROCESS_ARGUMENT
 * @def Processes a single command line argument, which may contain multiple
 *      numbers
 *		separated by spaces
 * @param
 * 	{t_data*} data - Main structure where to load the data
 * 	{char*} arg - Command line argument to process
 * @returns
 *		OK - FALSE (0) if argument was processed successfully
 *		KO - TRUE (1) if validation error or memory allocation fails
 * @cond
 *		- data cannot be NULL
 *		- arg cannot be NULL
 *		- data->stack_a must be initialized
 * */
static int	ft_process_argument(t_data *data, char *arg)
{
	char	**tokens;
	int		num;

	if (ft_strchr(arg, ' ') != NULL)
	{
		tokens = ft_split_args(arg);
		if (tokens == NULL)
			return (TRUE);
		if (ft_process_tokens(data, tokens) == TRUE)
		{
			ft_free_split(tokens);
			return (TRUE);
		}
		ft_free_split(tokens);
	}
	else
	{
		if (ft_validate_input_number(data, arg, &num) == TRUE)
			return (TRUE);
		if (ft_data_stack_a_add(data, num) == FALSE)
			return (TRUE);
	}
	return (FALSE);
}

/* FT_PARSE_AND_LOAD
 * @def Processes command line arguments and loads numbers into data structure
 * @param
 * 	{int} argc - Number of command line arguments
 * 	{char**} argv - Array of command line argument strings
 * @returns
 *		OK - Pointer to t_data structure with loaded numbers
 *		KO - NULL if memory allocation fails or validation error occurs
 * @cond
 *		- argv must be a valid NULL-terminated array
 *		- argc must be at least 2 to have arguments to parse
 * */
t_data	*ft_parse_and_load(int argc, char **argv)
{
	t_data	*data;
	int		i;

	data = ft_data_new();
	if (data == NULL)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (ft_process_argument(data, argv[i]) == TRUE)
		{
			ft_data_free(data);
			return (NULL);
		}
		i++;
	}
	return (data);
}
