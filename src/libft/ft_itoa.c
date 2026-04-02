/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-18 17:04:53 by rjuarez-          #+#    #+#             */
/*   Updated: 2025-10-18 17:04:53 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n);

static int	ft_intlen(long n);

static int	ft_intlen(long n)
{
	int		i;
	long	aux;

	i = 0;
	aux = n;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		aux = aux * -1;
	}
	while (aux > 0)
	{
		aux = aux / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;
	long	num;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = ft_intlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	num = sign * (long)n;
	str[len] = '\0';
	len--;
	if (n == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[len--] = (num % 10) + '0';
		num = num / 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
