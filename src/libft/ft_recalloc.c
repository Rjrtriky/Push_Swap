/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 17:25:45 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/02 17:29:11 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_recalloc(unsigned char *old_ptr, unsigned long int new_size);

/* FT_RECALLOC
 * @def Reallocates memory with initialization of new memory to zero
 * @param
 * 	{unsigned char*} old_ptr - Pointer to previously allocated memory 
 * 							   (can be NULL)
 * 	{unsigned long int} new_size - New size in bytes to allocate
 * @returns
 *		OK - Pointer to the newly allocated memory (old_ptr is freed)
 *		KO - NULL if new_size is 0 or memory allocation fails
 * @cond
 *		- If new_size is 0, old_ptr is freed and NULL is returned
 *		- If old_ptr is NULL, behaves like ft_calloc(new_size, 1)
 *		- New memory is zero-initialized using ft_calloc
 *		- Only up to the smaller of old_size and new_size bytes are copied
 *		- old_size is determined using ft_strlen on old_ptr
 * */
void	*ft_recalloc(unsigned char *old_ptr, unsigned long int new_size)
{
	unsigned char	*new_ptr;
	long long int	i;
	size_t			old_size;

	if (new_size == 0)
	{
		free(old_ptr);
		return (NULL);
	}
	new_ptr = (unsigned char *) ft_calloc(new_size, 1);
	if (new_ptr == NULL)
		return (NULL);
	if (old_ptr != NULL)
	{
		old_size = ft_strlen((char *) old_ptr);
		i = -1;
		while ((++i < (int) old_size) && (i < (int) new_size))
			new_ptr[i] = old_ptr[i];
	}
	free(old_ptr);
	old_ptr = new_ptr;
	return (new_ptr);
}
