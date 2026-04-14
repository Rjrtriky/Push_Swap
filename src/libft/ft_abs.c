/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:49:22 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/02 17:20:31 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* FT_ABS
 * @def Returns the absolute value of a signed long long integer,
 *      converted to unsigned long integer.
 *
 * @param
 *      {long long int} nbr - number to convert.
 *
 * @returns {unsigned long int}
 *      OK - Absolute value of nbr, cast to unsigned long int.
 */

int	ft_abs(int num);

int	ft_abs(int num)
{
	if (num >= 0)
		return (num);
	else
		return (-1 * num);
}
