/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-18 16:59:15 by rjuarez-          #+#    #+#             */
/*   Updated: 2025-10-18 16:59:15 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *s);

static int	ft_strspaces(const char c);

static int	ft_strspaces(const char c)
{
	if ((c == ' ') || (c == '\t') || (c == '\n') || (c == '\v') || (c == '\f')
		|| (c == '\r'))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *s)
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
		if ((signal * aux) <= (INT_MIN +1))
			return (INT_MIN);
		if ((signal * aux) >= INT_MAX)
			return (INT_MAX);
		i++;
	}
	return (signal * aux);
}
