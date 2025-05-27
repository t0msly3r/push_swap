/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiz-ben <tfiz-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:40:14 by tfiz-ben          #+#    #+#             */
/*   Updated: 2025/05/27 11:04:12 by tfiz-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../lib/libft.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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

// setters.c
void				set_target(t_stack **a, t_stack **b);
void				set_index(t_stack **ab);
void				set_costs(t_stack **a, t_stack **b);
void				set_all(t_stack **a, t_stack **b);

// algorithms
void				sort_three(t_stack **a);
void				sort_five(t_stack **a, t_stack **b);
void				sort_large(t_stack **a, t_stack **b);
void				sort(t_stack **a, t_stack **b);
t_stack				*find_cheapest(t_stack **b);

// getters.c
void				get_arguments(char **arg, t_stack **a);
void				get_arguments2(char **argv, t_stack **a, int argc,
						int start);
int					get_index(t_stack **a, int value);
int					get_target(t_stack *a, int value);

// checkers.c
int					check_duplicates(t_stack **a);
int					is_sorted(t_stack **a);
int					check_argument(char *arg);

// utils_*.c
int					stacklen(t_stack **a);
void				fill_stack(t_stack **a, int value);
void				free_stack(t_stack *a);
void				move_to_top(t_stack **stack, int value, char c);
long				ft_atol(const char *str);
int					find_min(t_stack *stack);
void				min_to_top(t_stack **a, int min_idx, int size_a,
						int min_value);
int					calculate_total_cost(int cost_a, int cost_b);
void				execute_moves(t_stack **a, t_stack **b, int cost_a,
						int cost_b);
void				ft_free_split(char **split);

// movements
void				push(t_stack **src, t_stack **dest, char t_stack);
void				swap(t_stack **ab, char stac);
void				rotate(t_stack **ab, char t_stack);
void				reverse_rotate(t_stack **ab, char t_stack);
void				rrr(t_stack **a, t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rrotate_s(t_stack **ab, int *cost, char c);
void				rotate_s(t_stack **ab, int *cost, char c);
void				push_b(t_stack **a, t_stack **b);

#endif