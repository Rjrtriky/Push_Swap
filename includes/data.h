/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 04:15:06 by rjuarez-          #+#    #+#             */
/*   Updated: 2026/02/24 18:02:44 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
// ========== Libraries ========== //
# include <stddef.h>
# include <stdlib.h>
// =========== Structs =========== //

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*previous;
	int				num;
	int				index;
	int				cost_rot_a;
	int				cost_rot_b;
	int				cost_total;
	struct s_node	*target;
}		t_node;

typedef struct s_stack
{
	t_node	*first_node;
	t_node	*end_node;
	int		size;
}		t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		n_nodes;
}		t_data;

// =================================== //
// -------- DATA --------------------- //
// -------- Builders Data ------------ //
t_data	*ft_data_new(void);
// -------- Erased Data -------------- //
int		ft_data_free(t_data *data);
// -------- Actions Data ------------- //
int		ft_data_stack_a_add(t_data *data, int nbr);
int		ft_data_stack_b_add(t_data *data, int nbr);
// =================================== //
// -------- STACK -------------------- //
// -------- Builders Stack ----------- //
t_stack	*ft_stack_new(void);
// -------- Erased Stack ------------- //
int		ft_stack_free(t_stack *stack);
// =================================== //
// -------- NODE --------------------- //
// -------- Builders Node ------------ //
t_node	*ft_node_new(int nbr);
// -------- Erased Node -------------- //
int		ft_node_free(t_node *node);
// =================================== //
// -------- UTILS -------------------- //
void	ft_stack_index(t_stack *stack);
int		ft_stack_add(t_stack *stack, t_node *node);
int		ft_stack_add_end(t_stack *stack, t_node *node);
t_node	*ft_stack_pop(t_stack *stack);
t_node	*ft_stack_pop_end(t_stack *stack);

#endif
