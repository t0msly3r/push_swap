/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiz-ben <tfiz-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:40:04 by tfiz-ben          #+#    #+#             */
/*   Updated: 2025/05/23 16:12:07 by tfiz-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stacklen(t_stack **a)
{
	int		i;
	t_stack	*temp;

	temp = *a;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	find_target(t_stack *a, int value)
{
	int		target;
	t_stack	*temp;

	target = __INT_MAX__;
	temp = a;
	while (temp)
	{
		if ((value < temp->value) && (temp->value < target))
		{
			target = temp->value;
		}
		temp = temp->next;
	}
	if (target == __INT_MAX__)
	{
		temp = a;
		target = temp->value;
		while (temp)
		{
			if (temp->value < target)
				target = temp->value;
			temp = temp->next;
		}
	}
	return (target);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	execute_moves(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b);
		cost_a++;
		cost_b++;
	}
	rotate_s(a, &cost_a, 'a');
	rrotate_s(a, &cost_a, 'a');
	rotate_s(b, &cost_b, 'b');
	rrotate_s(b, &cost_b, 'b');
}

int	calculate_total_cost(int cost_a, int cost_b)
{
	int	total;
	int	max_cost;

	total = 0;
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
	{
		if (ft_abs(cost_a) > ft_abs(cost_b))
			max_cost = ft_abs(cost_a);
		else
			max_cost = ft_abs(cost_b);
		total = max_cost;
	}
	else
		total = ft_abs(cost_a) + ft_abs(cost_b);
	return (total);
}
