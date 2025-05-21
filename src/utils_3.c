#include "../include/push_swap.h"

int	stacklen(t_stack **a)
{
	int		i;
    t_stack    *temp;

    temp = *a;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int find_target(t_stack *a, int value)
{
    int target = __INT_MAX__;
    t_stack *temp = a;

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

t_stack *find_cheapest(t_stack **b)
{
    t_stack *temp = *b;
    t_stack *cheapest = temp;

    while (temp)
    {
        if (temp->cost_a + temp->cost_b < cheapest->cost_a + cheapest->cost_b)
            cheapest = temp;
        temp = temp->next;
    }
    return (cheapest);
}

int get_index(t_stack **a, int value)
{
    t_stack *temp = *a;
    int index = 0;

    while (temp)
    {
        if (temp->value == value)
            return index;
        temp = temp->next;
        index++;
    }
    return (-1);
}

int is_sorted(t_stack **a)
{
    t_stack *temp = *a;

    while (temp && temp->next)
    {
        if (temp->value > temp->next->value)
            return 0;
        temp = temp->next;
    }
    return 1;
}
