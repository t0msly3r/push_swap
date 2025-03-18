/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiz-ben <tfiz-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:35:52 by tfiz-ben          #+#    #+#             */
/*   Updated: 2025/03/11 16:40:16 by tfiz-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "push_swap.h"

int	check_stacks(t_stack **a, t_stack **b)
{
	if (is_sorted(a) && is_sorted_reverse(b))
		return (1);
	return (0);
}

void	print_stack(t_stack *a)
{
	t_stack	*temp;

	temp = a;
	while (temp)
	{
		printf("%d ",temp->value);
		temp = temp->next;
	}
}
