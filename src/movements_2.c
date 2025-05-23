/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiz-ben <tfiz-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:40:02 by tfiz-ben          #+#    #+#             */
/*   Updated: 2025/05/23 16:10:10 by tfiz-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_b(t_stack **a, t_stack **b)
{
	while (stacklen(a) > 3)
	{
		push(a, b, 'b');
	}
}

void	rotate_s(t_stack **ab, int *cost, char c)
{
	while (*cost > 0)
	{
		rotate(ab, c);
		(*cost)--;
	}
}

void	rrotate_s(t_stack **ab, int *cost, char c)
{
	while (*cost < 0)
	{
		reverse_rotate(ab, c);
		(*cost)++;
	}
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, 'x');
	rotate(b, 'x');
	write(1, "rr\n", 3);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a, 'x');
	reverse_rotate(b, 'x');
	write(1, "rrr\n", 4);
}
