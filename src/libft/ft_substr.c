/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-18 19:18:22 by rjuarez-          #+#    #+#             */
/*   Updated: 2025-10-18 19:18:22 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(size_t len1, size_t len2, unsigned int st);

char			*ft_substr(char const *s, unsigned int start, size_t len);

static size_t	ft_size(size_t len1, size_t len2, unsigned int st)
{
	if (st >= len2)
		return (0);
	if (len1 > (len2 - st))
		return (len2 - st);
	else
		return (len1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen((char *)s);
	ptr = (char *)malloc((ft_size(len, s_len, start) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	if (start >= s_len)
		ptr[i] = '\0';
	else
	{
		while (s[start + i] != '\0' && (i < len))
		{
			ptr[i] = s[start + i];
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}


