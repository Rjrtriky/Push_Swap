/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-18 17:08:23 by rjuarez-          #+#    #+#             */
/*   Updated: 2025-10-18 17:08:23 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *org, size_t len);

void	*ft_memcpy(void *dest, const void *org, size_t len)
{
	size_t	i;
	char	*aux_dest;
	char	*aux_org;

	if ((dest == NULL) && (org == NULL))
		return (NULL);
	i = 0;
	aux_dest = (char *)dest;
	aux_org = (char *)org;
	while (i < len)
	{
		*aux_dest = *aux_org;
		aux_dest++;
		aux_org++;
		i++;
	}
	return (dest);
}
