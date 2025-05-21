#include "../include/push_swap.h"

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

void	set_target(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *a;
	temp_b = *b;
	while (temp_b)
	{
		temp_b->target = find_target(temp_a, temp_b->value);
		temp_b = temp_b->next;
	}
}

void	set_costs(t_stack **a, t_stack **b)
{
	int		size_a = stacklen(a);
	int		size_b = stacklen(b);
	t_stack	*temp_b = *b;
	int		target_pos;

	temp_b = *b;
	size_a = stacklen(a);
	size_b = stacklen(b);
	set_index(a);
	set_index(b);
	while (temp_b)
	{
		if (temp_b->index <= size_b / 2)
			temp_b->cost_b = temp_b->index;
		else
			temp_b->cost_b = -(size_b - temp_b->index);
		target_pos = get_index(a, temp_b->target);
		if (target_pos <= size_a / 2)
			temp_b->cost_a = target_pos;
		else
			temp_b->cost_a = -(size_a - target_pos); 
		temp_b = temp_b->next;
	}
}
