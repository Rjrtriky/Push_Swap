/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:05:21 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/02/24 14:41:18 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "moves.h"
#include "push_swap.h"

t_data	*ft_fill(int argc, char *argv[]);

t_data	*ft_fill(int argc, char *argv[])
{
	int		i;
	int		err;
	t_data	data;

	data = ft_data_new();
	i = argc;
	while ((i-- > 0) && (err == 0))
	{
		err = ft_data_stack_a_add(data, argv[i]);
		imprimir(data);
	}
	if (err == 1)
	{
		ft_data_free(data);
		return (NULL);
	}
	return (data);
}

int main(int argc, char *argv[])
{
	t_data	data;

	data = ft_fill(argc, argv);
	ft_data_free(data);

	return (0);
}