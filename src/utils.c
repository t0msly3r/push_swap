/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiz-ben <tfiz-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:40:07 by tfiz-ben          #+#    #+#             */
/*   Updated: 2025/05/23 16:10:20 by tfiz-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack *a)
{
	t_stack	*temp;

	while (a)
	{
		temp = a;
		a = a->next;
		free(temp);
	}
}

void	fill_stack(t_stack **a, int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = *a;
	*a = new_node;
}

int	find_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

void	move_to_top(t_stack **stack, int value, char c)
{
	int		pos;
	int		size;
	t_stack	*tmp;

	pos = 0;
	size = stacklen(stack);
	tmp = *stack;
	while (tmp && tmp->value != value)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= size / 2)
	{
		while ((*stack)->value != value)
			rotate(stack, c);
	}
	else
	{
		while ((*stack)->value != value)
		{
			reverse_rotate(stack, c);
		}
	}
}

void	min_to_top(t_stack **a, int min_idx, int size_a, int min_value)
{
	if (min_idx <= size_a / 2)
	{
		while ((*a)->value != min_value)
			rotate(a, 'a');
	}
	else
	{
		while ((*a)->value != min_value)
			reverse_rotate(a, 'a');
	}
}
