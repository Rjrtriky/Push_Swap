/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:59:15 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/03/31 23:56:43 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atol(const char *s);
static int	ft_strspaces(const char c);

/* FT_STRSPACES (static helper function)
 * @def Checks if a character is a whitespace character
 * @param
 * 	{const char} c - Character to check
 * @returns
 *		OK - 1 if character is whitespace (space, tab, newline, vertical tab,
 *			 form feed, carriage return)
 *		KO - 0 if character is not whitespace
 * @cond
 *		- Function is static and only used within ft_atol
 * */
static int	ft_strspaces(const char c)
{
	if ((c == ' ') || (c == '\t') || (c == '\n') || (c == '\v') || (c == '\f')
		|| (c == '\r'))
		return (1);
	else
		return (0);
}

/* FT_ATOL
 * @def Converts a string to a long integer, handling leading spaces and an 
 *      optional sign
 * @param
 * 	{const char*} str - String to convert
 * @returns
 *		OK - Long integer value of the converted string
 *		KO - 0 if no digits found (returns 0, but this is also a valid
             conversion)
 * @cond
 *		- str cannot be NULL
 *		- String may contain leading whitespaces (space, tab, newline, etc.)
 *		- String may have one optional '+' or '-' sign before digits
 *		- Conversion stops at first non-digit character
 * */
long	ft_atol(const char *s)
{
	long	aux;
	int		signal;
	int		i;

	i = 0;
	aux = 0;
	signal = 1;
	while ((ft_strspaces(s[i]) == 1) && (s[i] != '\0'))
		i++;
	if ((s[i] == '-') || (s[i] == '+'))
	{
		if (s[i] == '-')
			signal = -1;
		i++;
	}
	while ((ft_isdigit(s[i]) == 1) && (s[i] != '\0'))
	{
		aux = (aux * 10) + (s[i] - '0');
		i++;
	}
	return (signal * aux);
}
