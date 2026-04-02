/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:04:07 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/01 21:23:46 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int nbr);

int	ft_isdigit(int nbr)
{
	if ((nbr >= 48) && (nbr <= 57))
		return (TRUE);
	else
		return (FALSE);
}
