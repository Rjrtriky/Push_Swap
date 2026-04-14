/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:19:25 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/02 17:53:49 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

/* FT_REGISTER
 * @def Registers (prints) a performed move to standard output
 * @param
 * 	{char*} mov - String with the move name to print
 * @returns
 *		OK - void (no return value)
 *		KO - void (no return value)
 * @cond
 *		- mov cannot be NULL
 *		- mov must be a valid move string (e.g., "sa", "pb", "ra", etc.)
 * */
void	ft_register(char *mov)
{
	ft_printf("%s\n", mov);
}
