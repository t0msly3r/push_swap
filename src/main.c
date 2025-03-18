/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiz-ben <tfiz-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:09:50 by tfiz-ben          #+#    #+#             */
/*   Updated: 2025/03/11 17:30:23 by tfiz-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc >= 2)
	{
		a = NULL;
		b = NULL;
		if (argc == 2)
			get_arguments(argv, &a);
		else if (argc > 2)
			get_arguments2(argv, &a, argc, 1);
		if (check_duplicates(&a))
		{
			if (is_sorted(&a))
			{
				exit(-1);
			}
			set_nbr_digit(&a);
			sort_stacks(&a, &b);
			print_stack(a);
			free_stack(a);
		}
		else
			write(1, "Error/n", 6);
	}
	else
		write(1, "Error/n", 6);
}
