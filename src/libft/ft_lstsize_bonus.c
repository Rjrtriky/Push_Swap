/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-18 17:07:58 by rjuarez-          #+#    #+#             */
/*   Updated: 2025-10-18 17:07:58 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst);

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		count;

	count = 0;
	if (lst == NULL)
		return (count);
	current = lst;
	count = 1;
	while (current->next != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}
