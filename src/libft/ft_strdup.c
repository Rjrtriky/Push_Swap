/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-18 17:33:15 by rjuarez-          #+#    #+#             */
/*   Updated: 2025-10-18 17:33:15 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *ori);

char	*ft_strdup(const char *ori)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	len = ft_strlen((char *)ori);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = ori[i];
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}
