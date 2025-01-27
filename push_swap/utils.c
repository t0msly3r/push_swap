#include "push_swap.h"

int ft_strlen(char *a)
{
	int i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * neg);
}

void free_stack(stack *a)
{
	while (a)
	{
		stack *temp = a;
		a = a->next;
		free(temp);
	}
}

void print_stack(stack *a)
{
	while (a)
	{
		printf("%d", a->value);
		a = a->next;
	}
	printf("\n");
}

int	len_arg(char *arg)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (arg[i])
	{
		while (arg[i] == ' ')
			i++;
		len++;
		while (arg[i] != ' ')
			i++;
	}
	return (len);
}

void get_arguments(char **arg, stack **a)
{
	int	*temp;
	int	j;

	j = 0;
	temp = malloc(sizeof(int) * (len_arg(arg[1]) + 1));	
	while (*arg[1])
	{
		while (*arg[1] == ' ' && *arg[1])
			arg[1]++;
		if (*arg[1] == '\0')
			break ;
		temp[j] = ft_atoi(arg[1]);
		j++;
		while (*arg[1] != ' ' && *arg[1])
			arg[1]++;
	}
	temp[j] = 0;
	while (j >= 0)
	{
		fill_stack(a, temp[j]);
		j--;
	}
	free(temp);
}

int	check_duplicates(char *arg)
{
	char	temp[ft_strlen(arg)];
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (arg[i])
	{
		while (arg[i] == ' ')
			i++;
		while (temp[j] && arg[i] != temp[j])
			j++;
		if (arg[i] == temp[j])
			return (0);
		j = 0;
		temp[i] = arg[i];
		i++;
	}
	return (1);
}

void	fill_stack(stack **a, int value)
{
	stack *new_node = malloc(sizeof(stack));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = *a;
	*a = new_node;
}
