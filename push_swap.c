/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:16:50 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/02 18:13:06 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (0);
	data = ft_parse_and_load(argc, argv);
	if (data == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	ft_cost_based_algorithm(data);
	ft_data_free(data);
	return (0);
}
