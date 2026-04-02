/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:19:07 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/01 21:28:07 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*FT_STRTRIM
Descripcion: Elimina los caracteres especificados en 'set' al principio y al 
	final de la cadena s1.
Parametros de entrada :
	-s1: La string que debe ser recortada.
	-set: Los caracteres a eliminar de la string
Resultado:
	Correcto: Cadena recortada
	Error: NULL si falla al reservar memoria.
Comportamiento:
	1- Comprobar que los parametros no son nulos.
	2- Comprobamos por delante los caracteres de la cadena con respecto a todos
	los de set, hasta que no haya coincidencia.
	3- Comprobamos los por detras los caracteres de la cadena con respecto a 
	todos los de set, hasta que no haya coincidencia.
	4- Crear nueva cadena con malloc y se comprueba que se ha reservado memoria.
	5- Se copia los caracteres entre el inicio y final válidos.
	6- Se añade el caracter nulo al final.
	7- Devolver la nueva cadena.
Nota:
	1 = True
	0 = False*/

#include "libft.h"

static size_t	ft_inset(char c, char const *set);
static int		ft_strtrim_front(char const *s1, char const *set);
static int		ft_strtrim_back(char const *s1, char const *set);
char			*ft_strtrim(char const *s1, char const *set);

size_t	ft_inset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static int	ft_strtrim_front(char const *s1, char const *set)
{
	int	i;
	int	found;

	i = 0;
	found = 1;
	while ((s1[i] != '\0') && (found == 1))
	{
		found = ft_inset (s1[i], set);
		if (found == 1)
			i++;
	}
	return (i);
}

static int	ft_strtrim_back(char const *s1, char const *set)
{
	int	i;
	int	found;

	i = ft_strlen(s1);
	found = 1;
	i--;
	while ((i >= 0) && (found == 1))
	{
		found = ft_inset (s1[i], set);
		i--;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		front;
	int		back;
	char	*str;

	if (s1 == NULL)
		return (ft_calloc(1, (sizeof(char))));
	if (!set)
		return ((char *)s1);
	front = ft_strtrim_front(s1, set);
	back = ft_strtrim_back(s1, set);
	if (front > back)
		return (ft_calloc(1, (sizeof(char))));
	else
	{
		str = ft_substr(s1, front, back - front + 1);
		if (str == NULL)
			return (NULL);
		return (str);
	}
}
