#include "../include/push_swap.h"

void	print_stack(t_stack *a)
{
	t_stack	*temp;

	temp = a;
	while (temp)
	{
		printf("value:%d target:%d cost_a:%d cost_b:%d\n",temp->value, temp->target, temp->cost_a, temp->cost_b);
		temp = temp->next;
	}
}

void	show_stacks(t_stack **a, t_stack **b)
{
	printf("\nstack a: \n");
	print_stack(*a);
	printf("\nstack b: \n");
	print_stack(*b);
}

void move_to_top(t_stack **stack, int value, char c)
{
    int pos = 0;
    int size = stacklen(stack);
    t_stack *tmp = *stack;

    while (tmp && tmp->value != value)
    {
        pos++;
        tmp = tmp->next;
    }
    if (pos <= size / 2)
    {
        while ((*stack)->value != value)
            rotate(stack, c);
    }
    else
    {
        while ((*stack)->value != value)
        {
            reverse_rotate(stack, c);
        }
    }
}

int find_min(t_stack *stack)
{
    int min = stack->value;
    while (stack)
    {
        if (stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return min;
}

void	push_b(t_stack **a, t_stack **b)
{
	while (stacklen(a) > 3)
	{
		push(a, b, 'b');
	}
}

void rotate_s(t_stack  **ab, int *cost, char c)
{
    while (*cost > 0)
    {
        rotate(ab, c);
        (*cost)--;
    }
}

void rrotate_s(t_stack  **ab, int *cost, char c)
{
    while (*cost < 0)
    {
        reverse_rotate(ab, c);
        (*cost)++;
    }
}

void min_to_top(t_stack **a, int min_idx, int size_a, int min_value)
{
    if (min_idx <= size_a / 2)
    {
        while ((*a)->value != min_value)
            rotate(a, 'a');
    }
    else
    {
        while ((*a)->value != min_value)
            reverse_rotate(a, 'a');
    }
}
