/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-18 16:59:53 by rjuarez-          #+#    #+#             */
/*   Updated: 2025-10-18 16:59:53 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *ptr, size_t len);

void	*ft_bzero(void *ptr, size_t len)
{
	unsigned char	*aux_ptr;
	size_t			i;

	i = 0;
	aux_ptr = ptr;
	while (i < len)
	{
		*aux_ptr = 0;
		aux_ptr++;
		i++;
	}
	return (ptr);
}
