/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiz-ben <tfiz-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:39:48 by tfiz-ben          #+#    #+#             */
/*   Updated: 2025/05/27 11:03:53 by tfiz-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 2)
		get_arguments(argv, &a);
	else if (argc > 2)
		get_arguments2(argv, &a, argc, 1);
	if (check_duplicates(&a) == 0)
	{
		write(1, "Error\n", 6);
		free_stack(a);
		return (0);
	}
	if (is_sorted(&a) == 1)
	{
		free_stack(a);
		return (0);
	}
	set_all(&a, &b);
	sort(&a, &b);
	free_stack(a);
	free_stack(b);
}
