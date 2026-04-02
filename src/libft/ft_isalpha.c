/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:03:43 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/01 21:24:26 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int nbr);

int	ft_isalpha(int nbr)
{
	if (((nbr >= 'A') && (nbr <= 'Z')) || ((nbr >= 'a') && (nbr <= 'z')))
		return (TRUE);
	else
		return (FALSE);
}
