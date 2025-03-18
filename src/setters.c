/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiz-ben <tfiz-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:17:14 by tfiz-ben          #+#    #+#             */
/*   Updated: 2025/03/10 13:12:54 by tfiz-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "push_swap.h"

void	set_index(t_stack **ab)
{
	int		i;
	t_stack	*temp;

	temp = *ab;
	i = 0;
	while (temp)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
}

void	set_last_digit(t_stack **ab, int pos)
{
	char	*char_value;
	t_stack	*temp;
	int		len;

	temp = *ab;
	while (temp)
	{
		char_value = ft_itoa(temp->value);
		len = ft_strlen(char_value);
		if (len <= pos)
			temp->last_digit = -1;
		else
			temp->last_digit = char_value[(len - 1) - pos] - '0';
		free(char_value);
		char_value = NULL;
		temp = temp->next;
	}
}

void	set_nbr_digit(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		temp->dig_nbr = count_digits(temp->value);
		temp = temp->next;
	}
}
