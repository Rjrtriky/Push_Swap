/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:03:15 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/01 21:24:15 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int nbr);

int	ft_isalnum(int nbr)
{
	if (((nbr >= 'A') && (nbr <= 'Z'))
		|| ((nbr >= 'a') && (nbr <= 'z'))
		|| ((nbr >= '0') && (nbr <= '9')))
		return (TRUE);
	else
		return (FALSE);
}
