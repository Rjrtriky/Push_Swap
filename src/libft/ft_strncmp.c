/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-18 18:08:12 by rjuarez-          #+#    #+#             */
/*   Updated: 2025-10-18 18:08:12 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size);

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t			i;
	unsigned int	dif;

	i = 0;
	dif = 0;
	while ((i < size) && (s1[i] != '\0') && (s2[i] != '\0') && (dif == 0))
	{
		dif = (unsigned char) s1[i] - (unsigned char) s2[i];
		i++;
	}
	if ((dif == 0) && (i < size))
		dif = (unsigned char) s1[i] - (unsigned char) s2[i];
	return (dif);
}
