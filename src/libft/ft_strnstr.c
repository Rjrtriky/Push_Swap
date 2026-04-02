/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-18 18:19:29 by rjuarez-          #+#    #+#             */
/*   Updated: 2025-10-18 18:19:29 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *srch, size_t len);

char	*ft_strnstr(const char *str, const char *srch, size_t len)
{
	size_t	i;
	size_t	j;

	if (srch[0] == '\0')
		return ((char *)str);
	i = 0;
	while ((i < len) && (str[i] != '\0'))
	{
		j = 0;
		while ((str[i + j] == srch[j]) && ((i + j) < len) && (srch[j] != '\0'))
		{
			j++;
		}
		if (srch[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
