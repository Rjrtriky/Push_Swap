/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 20:34:26 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/02 17:40:07 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft/libft.h"

// ft_conver_numbers.c
char				ft_conver_digital(unsigned char c);
int					ft_intlen_base(long long int nbr, int base);
unsigned long int	ft_uabs(long long int nbr);
char				*ft_conver_nbr_base(long long int nbr, int base);

// ft_conver.c
char				*ft_conver_null(char chr);
int					ft_conver_c(int chr);
char				*ft_conver_s(char *str);
char				*ft_conver_p(void *ptr);

// ft_puts.c
void				ft_putchr_fd(char c, int fd);
int					ft_puts_fd(char **text, int fd);

// ft_printf.c
int					ft_type_check(char chr, va_list p);
int					ft_printf(const char *format, ...);
char				*ft_strtoup(char **text);

#endif
