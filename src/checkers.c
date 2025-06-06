/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiz-ben <tfiz-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:05:10 by tfiz-ben          #+#    #+#             */
/*   Updated: 2025/05/23 16:59:27 by tfiz-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_duplicates(t_stack **a)
{
	int		temp[5000];
	int		i;
	int		j;
	t_stack	*temp2;

	temp2 = *a;
	j = 0;
	while (temp2)
	{
		i = 0;
		while (i < j)
		{
			if (temp[i] == temp2->value)
				return (0);
			i++;
		}
		temp[j] = temp2->value;
		temp2 = temp2->next;
		j++;
	}
	return (1);
}

int	is_sorted(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp && temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_argument(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isnum(arg[i]))
			return (0);
		i++;
	}
	return (1);
}
