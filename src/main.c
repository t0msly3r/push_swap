#include "../include/push_swap.h"

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
		set_index(&a);
        set_target(&a, &b);
        set_costs(&a, &b);
		// show_stacks(&a,&b);
		sort_large(&a, &b);
		free_stack(a);
		free_stack(b);
	}
	else
		write(1, "Error/n", 6);
}
