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

/* FT_FREE_SPLIT
 * @def Frees the memory of a token array created by ft_split_args
 * @param
 * 	{char**} tokens - Token array to free
 * @returns
 *		OK - void (no return value)
 *		KO - void (no return value)
 * @cond
 *		- tokens must be a valid NULL-terminated array
 * */
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

/* FT_COUNT_TOKENS
 * @def Counts how many tokens (numbers) are present in a string
 * @param
 * 	{char*} str - String to analyze
 * @returns
 *		OK - Number of tokens found in the string
 *		KO - 0 if str is NULL or empty
 * @cond
 *		- str must be a valid string
 * */

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

/* FT_COPY_TOKEN
 * @def Copies a token from a string starting at a given position
 * @param
 * 	{char*} str - Source string
 * 	{int*} i - Pointer to current position (updated during copy)
 * @returns
 *		OK - Newly allocated string containing the token
 *		KO - NULL if memory allocation fails
 * @cond
 *		- str cannot be NULL
 *		- i cannot be NULL
 *		- str[*i] must point to a valid character
 * */
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

/* FT_SPLIT_ARGS
 * @def Splits a string containing numbers separated by spaces into an array
 *      of tokens
 * @param
 * 	{char*} str - String to split
 * @returns
 *		OK - NULL-terminated array of token strings
 *		KO - NULL if str is NULL or memory allocation fails
 * @cond
 *		- str cannot be NULL
 *		- str must contain at least one token
 * */
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
