/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-18 17:07:27 by rjuarez-          #+#    #+#             */
/*   Updated: 2025-10-18 17:07:27 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *));

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	if ((lst == NULL) || (f == NULL))
		return ;
	current = lst;
	while (current != NULL)
	{
		f(current->content);
		current = current->next;
	}
}
