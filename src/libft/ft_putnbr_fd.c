/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-18 17:27:57 by rjuarez-          #+#    #+#             */
/*   Updated: 2025-10-18 17:27:57 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	char	digital;
	int		quotient;
	int		remainder;

	if (n < 0)
	{
		digital = '-';
		write (fd, &digital, 1);
		quotient = (n / 10) * -1;
		remainder = (n % 10) * -1;
	}
	else
	{
		quotient = n / 10;
		remainder = n % 10;
	}
	if (quotient != 0)
		ft_putnbr_fd(quotient, fd);
	digital = remainder + '0';
	write (fd, &digital, 1);
}
