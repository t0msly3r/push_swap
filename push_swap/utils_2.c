#include "push_swap.h"

int	stacklen(stack **a)
{
	int	i;

	i = 0;
	while ((*a))
	{
	*a = (*a)->next;
		i++;
	}
	return (i);
}

void	get_arguments2(char **argv, stack **a, int argc)
{
	int i;

	i = argc - 1;
	while (i >= 1)
	{
		fill_stack(a, ft_atoi(argv[i]));
		i--;
	}
}
