/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiz-ben <tfiz-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:02:57 by tfiz-ben          #+#    #+#             */
/*   Updated: 2025/05/23 16:55:35 by tfiz-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_arguments(char **arg, t_stack **a)
{
	char	**temp;
	int		arg_len;
	int		i;

	i = 0;
	arg_len = 0;
	temp = ft_split(arg[1], ' ');
	while (temp[arg_len])
		arg_len++;
	arg_len--;
	while (arg_len >= 0)
	{
		if (!check_argument(temp[arg_len]))
		{
			write(1, "Error\n", 6);
			ft_free_split(temp);
			free_stack(*a);
			exit(0);
		}
		fill_stack(a, ft_atoi(temp[arg_len]));
		arg_len--;
	}
	ft_free_split(temp);
}

void	get_arguments2(char **argv, t_stack **a, int argc, int start)
{
	int	i;

	i = argc - 1;
	while (i >= start)
	{
		if (!check_argument(argv[i]) || ft_atol(argv[i]) > 2147483647
			|| ft_atol(argv[i]) < -2147483648 || argv[i][0] == '\0')
		{
			write(1, "Error\n", 6);
			free_stack(*a);
			exit(0);
		}
		fill_stack(a, ft_atoi(argv[i]));
		i--;
	}
}

int	get_index(t_stack **a, int value)
{
	t_stack	*temp;
	int		index;

	temp = *a;
	index = 0;
	while (temp)
	{
		if (temp->value == value)
			return (index);
		temp = temp->next;
		index++;
	}
	return (-1);
}

int	get_target(t_stack *a, int value)
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
