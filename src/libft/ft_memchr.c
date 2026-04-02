/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-18 17:08:09 by rjuarez-          #+#    #+#             */
/*   Updated: 2025-10-18 17:08:09 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len);

void	*ft_memchr(const void *str, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)str;
	while (i < len)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
		i++;
	}
	return (NULL);
}
