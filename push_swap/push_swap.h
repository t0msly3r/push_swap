#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct s_list
{
	int		last_digt;
	int		value;
	int		pos;
	struct s_list *next;
} stack;

int		ft_atoi(const char *str);
void	fill_stack(stack **a, int value);
void	free_stack(stack *a);
void	print_stack(stack *a);
void	get_arguments(char **arg, stack **a);
int		check_duplicates(char *arg);
void	push(stack **src, stack **dest);
void	swap(stack **ab);
void	rotate(stack **ab);
void    reverse_rotate(stack **ab);
void	sort_three(stack **a);
int		stacklen(stack **a);
void	get_arguments2(char **argv, stack **a, int argc);
void	fill_stack(stack **a, int value);
int		len_arg(char *arg);

#endif