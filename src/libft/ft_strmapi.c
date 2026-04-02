/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-18 18:07:52 by rjuarez-          #+#    #+#             */
/*   Updated: 2025-10-18 18:07:52 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dest;

	if (s == NULL || f == NULL)
		return (NULL);
	dest = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
