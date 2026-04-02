/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:03:50 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/01 21:24:02 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int nbr);

int	ft_isascii(int nbr)
{
	if ((nbr >= 0) && (nbr <= 127))
		return (TRUE);
	else
		return (FALSE);
}
