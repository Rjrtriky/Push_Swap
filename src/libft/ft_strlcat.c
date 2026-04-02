/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-24 15:03:39 by rjuarez-          #+#    #+#             */
/*   Updated: 2025-10-24 15:03:39 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *ori, size_t size);

size_t	ft_strlcat(char *dst, const char *ori, size_t size)
{
	size_t	dst_len;
	size_t	ori_len;
	size_t	j;

	dst_len = ft_strlen(dst);
	ori_len = ft_strlen(ori);
	if (size <= dst_len)
		return (size + ori_len);
	j = 0;
	while ((dst_len + j) < (size - 1) && ori[j] != '\0')
	{
		dst[dst_len + j] = ori[j];
		j++;
	}
	dst[dst_len + j] = '\0';
	return (dst_len + ori_len);
}
