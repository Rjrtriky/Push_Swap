/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:04:38 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/01 21:36:09 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int nbr);

int	ft_isprint(int nbr)
{
	if ((nbr < 32) || (nbr > 126))
		return (FALSE);
	else
		return (TRUE);
}
