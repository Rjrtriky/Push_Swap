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
