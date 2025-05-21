/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiz-ben <tfiz-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:45:35 by tfiz-ben          #+#    #+#             */
/*   Updated: 2025/03/11 16:40:59 by tfiz-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../includes/libft.h"

typedef struct s_stack
{
	int				last_digit;
	int				value;
	int				index;
	int				dig_nbr;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

void				print_stack(t_stack *a);
void				sort_three(t_stack **a);
int					optimal_node(t_stack **ab, int digit);
int					find_biggest_nbr(t_stack **a);
void				sort_stacks(t_stack **a, t_stack **b);
void				move_top(int cost, t_stack **a);
int					count_digits(int nbr);
void				return_nodes(t_stack **a, t_stack **b, int len);
void				write_move(char *move, char ab);
int					is_sorted(t_stack **a);
int					is_sorted_reverse(t_stack **a);
int					check_stacks(t_stack **a, t_stack **b);
void				push_b(t_stack **a, t_stack **b);
void				show_stacks(t_stack **a, t_stack **b);
int					find_min(t_stack *stack);

// movements
void				push(t_stack **src, t_stack **dest, char t_stack);
void				swap(t_stack **ab, char stac);
void				rotate(t_stack **ab, char t_stack);
void				reverse_rotate(t_stack **ab, char t_stack);

// utils_*.c
int					find_target(t_stack *a, int value);
int					stacklen(t_stack **a);
void				fill_stack(t_stack **a, int value);
void				free_stack(t_stack *a);
void				get_arguments(char **arg, t_stack **a);
int					check_duplicates(t_stack	**a);
void				get_arguments2(char **argv, t_stack **a, int argc, int start);
void				fill_stack(t_stack **a, int value);
void				get_arguments(char **arg, t_stack **a);
void 				move_to_top(t_stack **stack, int value);
t_stack				*find_cheapest(t_stack **b);
int 				find_target(t_stack *a, int value);

// algorithms
void				sort_three(t_stack **a);
void 				sort_five(t_stack **a, t_stack **b);
void 				sort_large(t_stack **a, t_stack **b);
void 				sort(t_stack **a, t_stack **b);

// setters.c
void				set_target(t_stack **a, t_stack **b);
void				set_index(t_stack **ab);
void				set_costs(t_stack **a, t_stack **b);

#endif