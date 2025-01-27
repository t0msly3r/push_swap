#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		if (!check_duplicates(argv[1]))
		{
			printf("Error\n");
			return (0);
		}
		else
		{
			stack *a;
			//stack *b;

			a = NULL;
			//b = NULL;
			if (argc == 2)
				get_arguments(argv, &a);
			else if (argc > 2)
				get_arguments2(argv, &a, argc);
			print_stack(a);
			free_stack(a);
		}
	}
}
