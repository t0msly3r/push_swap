/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiz-ben <tfiz-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:09:43 by tfiz-ben          #+#    #+#             */
/*   Updated: 2025/03/11 17:25:04 by tfiz-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "push_swap.h"

int	stacklen(t_stack **a)
{
	int		i;
	t_stack	*head;

	head = *a;
	i = 0;
	while ((*a))
	{
		*a = (*a)->next;
		i++;
	}
	*a = head;
	return (i);
}

int	count_digits(int nbr)
{
	int	i;

	i = 0;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	find_biggest_nbr(t_stack **a)
{
	t_stack	*temp;
	int		dig_nbr;
	int		digits;

	dig_nbr = 0;
	temp = *a;
	while (temp)
	{
		digits = count_digits(temp->value);
		if (digits > dig_nbr)
		{
			dig_nbr = digits;
		}
		temp = temp->next;
	}
	return (dig_nbr);
}

int	is_sorted_reverse(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp->next)
	{
		if (temp->value < temp->next->value)
		{
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

int	is_sorted(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
		{
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}
