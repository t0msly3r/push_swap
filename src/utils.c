#include "../include/push_swap.h"

void	free_stack(t_stack *a)
{
	t_stack	*temp;

	while (a)
	{
		temp = a;
		a = a->next;
		free(temp);
	}
}

void	get_arguments(char **arg, t_stack **a)
{
	char	**temp;
	int		i;

	i = 0;
	temp = ft_split(arg[1], ' ');
	while (temp[i])
	{
		i++;
	}
	get_arguments2(temp, a, i, 0);
}

int	check_duplicates(t_stack **a)
{
	int	temp[5000];
	int	i;
	int	j;
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

void	fill_stack(t_stack **a, int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = *a;
	*a = new_node;
}

void	get_arguments2(char **argv, t_stack **a, int argc, int start)
{
	int	i;

	i = argc - 1;
	while (i >= start)
	{
		fill_stack(a, ft_atoi(argv[i]));
		i--;
	}
}
