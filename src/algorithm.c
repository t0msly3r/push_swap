/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiz-ben <tfiz-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:10:00 by tfiz-ben          #+#    #+#             */
/*   Updated: 2025/03/18 14:35:59 by tfiz-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "push_swap.h"

void	move_top(int cost, t_stack **a)
{
	int		mid;
	t_stack	*temp;
	t_stack	*node;

	node = *a;
	temp = *a;
	mid = stacklen(a) / 2;
	while (node->index != cost)
		node = node->next;
	while (node->index != 0)
	{
		if (cost >= mid)
			reverse_rotate(&temp, 'a');
		else
			rotate(&temp, 'a');
	}
	*a = temp;
}

void	return_nodes(t_stack **a, t_stack **b, int len)
{
	t_stack	*start;
	int		size;
	int		count;

	if (!*b)
		return ;
	start = *b;
	size = stacklen(b);
	count = 0;
	while (count < size)
	{
		if ((*b)->dig_nbr > len)
		{
			push(b, a, 'b');
		}
		else
		{
			rotate(b, 'b');
		}
		count++;
		if (*b == start)
			break ;
	}
}

int	head_node(t_stack **a, int digit)
{
	int		lower;
	int		index;
	t_stack	*temp;

	index = -1;
	temp = *a;
	lower = -1;
	while (temp)
	{
		if (temp->last_digit == digit)
		{
			if (lower == -1)
			{
				lower = temp->value;
				index = temp->index;
			}
			else if (temp->value < lower)
			{
				lower = temp->value;
				index = temp->index;
			}
		}
		temp = temp->next;
	}
	return (index);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int		digit;
	t_stack	*temp;
	int		cost;

	digit = 0;
	temp = *a;
	while (digit <= 9)
	{
		cost = head_node(&temp, digit);
		if (cost >= 0)
		{
			move_top(cost, a);
			push(a, b, 'a');
		}
		else
			digit++;
		temp = *a;
	}
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	dig_nbr;
	int	i;
	int	pos;

	pos = 0;
	i = 0;
	dig_nbr = find_biggest_nbr(a);
	set_index(a);
	while (i < dig_nbr)
	{
		set_last_digit(a, pos);
		radix_sort(a, b);
		return_nodes(a, b, (pos + 1));
		if (find_biggest_nbr(a) > 1)
			if (check_stacks(a, b))
				break ;
		pos++;
		i++;
	}
	while (*b)
	{
		push(b, a, 'b');
	} 
}
