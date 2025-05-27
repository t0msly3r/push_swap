/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiz-ben <tfiz-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:39:44 by tfiz-ben          #+#    #+#             */
/*   Updated: 2025/05/27 11:09:40 by tfiz-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && first > third)
		rotate(a, 'a');
	else if (second > first && second > third)
		reverse_rotate(a, 'a');
	first = (*a)->value;
	second = (*a)->next->value;
	if (first > second)
		swap(a, 'a');
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min;
	int	size;

	size = stacklen(a);
	while (stacklen(a) > 3)
	{
		min = find_min(*a);
		move_to_top(a, min, 'a');
		push(a, b, 'b');
	}
	sort_three(a);
	while (*b)
		push(b, a, 'a');
}


t_stack	*find_cheapest(t_stack **b)
{
	t_stack	*temp;
	t_stack	*cheapest;
	int		min_cost;
	int		total_cost;

	temp = *b;
	cheapest = temp;
	min_cost = calculate_total_cost(temp->cost_a, temp->cost_b);
	temp = temp->next;
	while (temp)
	{
		total_cost = calculate_total_cost(temp->cost_a, temp->cost_b);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			cheapest = temp;
		}
		temp = temp->next;
	}
	return (cheapest);
}

void	sort_large(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	int		min_value;
	int		min_idx;
	int		size_a;

	min_value = find_min(*a);
	min_idx = get_index(a, min_value);
	size_a = stacklen(a);
	push_b(a, b);
	sort_three(a);
	while (*b)
	{
		set_target(a, b);
		set_costs(a, b);
		cheapest = find_cheapest(b);
		execute_moves(a, b, cheapest->cost_a, cheapest->cost_b);
		push(b, a, 'a');
	}
	min_to_top(a, min_idx, size_a, min_value);
}

void	sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stacklen(a);
	if (size == 2)
		swap(a, 'a');
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		sort_large(a, b);
}
