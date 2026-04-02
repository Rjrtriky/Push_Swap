/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 20:31:21 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/02 13:09:56 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		ft_free_split(char **tokens);
static int	ft_count_tokens(char *str);
static char	*ft_copy_token(char *str, int *i);
char		**ft_split_args(char *str);

void	ft_free_split(char **tokens)
{
	int	i;

	if (tokens == NULL)
		return ;
	i = 0;
	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

static int	ft_count_tokens(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0')
			count++;
		while ((str[i] != '\0') && (str[i] != ' '))
			i++;
	}
	return (count);
}

static char	*ft_copy_token(char *str, int *i)
{
	int		start;
	int		len;
	char	*token;

	while (str[*i] == ' ')
		(*i)++;
	start = *i;
	while ((str[*i] != '\0') && (str[*i] != ' '))
		(*i)++;
	len = *i - start;
	token = malloc((len + 1) * sizeof(char));
	if (token == NULL)
		return (NULL);
	ft_memcpy(token, str + start, len);
	token[len] = '\0';
	return (token);
}

char	**ft_split_args(char *str)
{
	char	**tokens;
	int		count;
	int		i;
	int		j;

	if (str == NULL)
		return (NULL);
	count = ft_count_tokens(str);
	tokens = malloc((count + 1) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count)
	{
		tokens[j] = ft_copy_token(str, &i);
		if (tokens[j] == NULL)
		{
			ft_free_split(tokens);
			return (NULL);
		}
		j++;
	}
	tokens[j] = NULL;
	return (tokens);
}
