/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 03:37:15 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/04/02 17:02:24 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H
// ========== Libraries ========== //
# include "../data/data.h"
# include "../ft_printf/ft_printf.h"

/*sa (intercambiar a): Intercambia los dos primeros elementos de la parte
superior de la pila a.
No haces nada si solo hay un elemento o no hay ninguno.
sb (intercambiar b): Intercambia los dos primeros elementos de la parte 
superior de la pila b.
No haces nada si solo hay un elemento o no hay ninguno.
ss: sa y sb simultáneamente.

pa (empujar a): Toma el primer elemento de la parte superior de b y colócalo en
la parte superior de a.
No haces nada si b está vacío. 
pb (empujar b): Toma el primer elemento en la parte superior de a y colócalo en
la parte superior de b.
No hacer nada si a está vacío.

ra (rotar a): Desplaza todos los elementos de la pila a en 1 posición.
El primer elemento se convierte en el último.
rb (rotar b): Desplaza todos los elementos de la pila b en 1 posición.
El primer elemento se convierte en el último.
rr: ra y rb simultáneamente.

rra (rotar a en sentido inverso): Desplaza todos los elementos de la pila a
en 1 posición.
El último elemento se convierte en el primero.
rrb (rotar b en sentido inverso): Desplaza todos los elementos de la pila b
en 1 posición.
El último elemento se convierte en el primero.
rrr: rra y rrb simultáneamente.
*/

// ======= Function Prototypes ======= //
// -------------- SWAP --------------- //
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	ft_swap(t_stack *stack);
// -------------- PUSH -------------- //
void	pa(t_data *data);
void	pb(t_data *data);
void	ft_push(t_stack *stack_ori, t_stack *stack_des);
// --------------ROTATE ------------- //
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	ft_rotate(t_stack *stack);
// --------- REVERSE ROTATE --------- //
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
void	ft_reverse_rotate(t_stack *stack);
// --------- MOVES_UTILS ------------ //
void	ft_register(char *mov);
#endif
