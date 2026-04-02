/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-18 17:00:26 by rjuarez-          #+#    #+#             */
/*   Updated: 2025-10-18 17:00:26 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size);

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if ((num == 0) || (size == 0))
		return (malloc(0));
	if (size > 0 && num > __SIZE_MAX__ / size)
		return (NULL);
	ptr = malloc(num * size);
	if ((ptr == NULL) || (ft_bzero(ptr, (num * size)) != ptr))
		return (NULL);
	else
		return (ptr);
}
