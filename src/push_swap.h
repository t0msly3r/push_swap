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

typedef struct s_stack
{
	int				last_digit;
	int				value;
	int				index;
	int				dig_nbr;
	struct s_stack	*next;
}					t_stack;

int					ft_atoi(const char *str);
void				fill_stack(t_stack **a, int value);
void				free_stack(t_stack *a);
void				print_stack(t_stack *a);
void				get_arguments(char **arg, t_stack **a);
int					check_duplicates(t_stack	**a);
void				push(t_stack **src, t_stack **dest, char t_stack);
void				swap(t_stack **ab, char stac);
void				rotate(t_stack **ab, char t_stack);
void				reverse_rotate(t_stack **ab, char t_stack);
void				sort_three(t_stack **a);
int					stacklen(t_stack **a);
void				get_arguments2(char **argv, t_stack **a, int argc, int start);
void				fill_stack(t_stack **a, int value);
void				get_arguments(char **arg, t_stack **a);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s);
int					optimal_node(t_stack **ab, int digit);
void				set_last_digit(t_stack **ab, int pos);
int					find_biggest_nbr(t_stack **a);
void				set_index(t_stack **ab);
void				sort_stacks(t_stack **a, t_stack **b);
void				move_top(int cost, t_stack **a);
int					count_digits(int nbr);
void				return_nodes(t_stack **a, t_stack **b, int len);
void				set_nbr_digit(t_stack **a);
void				write_move(char *move, char ab);
int					is_sorted(t_stack **a);
int					is_sorted_reverse(t_stack **a);
int					check_stacks(t_stack **a, t_stack **b);

#endif