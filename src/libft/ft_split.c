/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-18 17:32:45 by rjuarez-          #+#    #+#             */
/*   Updated: 2025-10-18 17:32:45 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_split(char const *s, char c);

static int	ft_newstr(char ***dest, char const *str, char c);

static int	ft_strlen_cs(char const *str, char c, int start);

static int	ft_strcopy(const char *ori, char **dest, char c, int start);

static void	ft_split_free(char ***dest);

static int	ft_newstr(char ***dest, char const *str, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if ((str[i] != c) && (str[i] != '\0'))
			count++;
		while ((str[i] != c) && (str[i] != '\0'))
			i++;
	}
	*dest = (char **) ft_calloc((count + 1), sizeof(char *));
	if (*dest == NULL)
		return (-1);
	(*dest)[count] = NULL;
	return (count);
}

static int	ft_strlen_cs(char const *str, char c, int start)
{
	int	i;

	i = 0;
	while ((str[start + i] != c) && (str[start + i] != '\0'))
		i++;
	return (i);
}

static int	ft_strcopy(const char *ori, char **dest, char c, int start)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	len = ft_strlen_cs(ori, c, start);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (-1);
	while (i < len)
	{
		ptr[i] = ori[start + i];
		i++;
	}
	ptr[i] = '\0';
	*dest = ptr;
	return (start + len);
}

static void	ft_split_free(char ***dest)
{
	int	i;

	i = 0;
	while ((*dest)[i])
	{
		free((*dest)[i]);
		i++;
	}
	free(*dest);
	*dest = NULL;
	return ;
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		numstr;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	dest = NULL;
	numstr = ft_newstr(&dest, s, c);
	if (numstr == -1)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < numstr)
	{
		while (s[j] == c)
			j++;
		j = ft_strcopy(s, &dest[i], c, j);
		if (dest[i] == NULL)
		{
			ft_split_free (&dest);
			return (NULL);
		}
	}
	return (dest);
}
