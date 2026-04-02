/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-18 17:33:25 by rjuarez-          #+#    #+#             */
/*   Updated: 2025-10-18 17:33:25 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if ((s != NULL) && (f != NULL))
	{
		i = 0;
		while (s[i] != '\0')
		{
			f(i, &s[i]);
			i++;
		}
	}
}
