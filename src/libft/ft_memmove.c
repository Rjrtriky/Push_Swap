/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-24 15:06:09 by rjuarez-          #+#    #+#             */
/*   Updated: 2025-10-24 15:06:09 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *des, const void *ori, size_t size);

void	*ft_memmove(void *des, const void *ori, size_t size)
{
	unsigned char	*aux_ori;
	unsigned char	*aux_des;
	size_t			i;

	if ((des == NULL) && (ori == NULL))
		return (NULL);
	aux_ori = (unsigned char *)ori;
	aux_des = (unsigned char *)des;
	i = size;
	if (aux_des > aux_ori)
	{
		while (i > 0)
		{
			i--;
			aux_des[i] = aux_ori[i];
		}
	}
	else if (aux_des < aux_ori)
	{
		while (i--)
		{
			*aux_des++ = *aux_ori++;
		}
	}
	return (des);
}
