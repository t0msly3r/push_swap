#include "../include/push_swap.h"

void	sort_three(t_stack **a)
{
    int first = (*a)->value;
    int second = (*a)->next->value;
    int third = (*a)->next->next->value;

    if (first > second && first > third)
        rotate(a, 'a');
    else if (second > first && second > third)
        reverse_rotate(a, 'a');
    first = (*a)->value;
    second = (*a)->next->value;
    if (first > second)
        swap(a, 'a');
}


void sort_five(t_stack **a, t_stack **b)
{
    int min;

    min = find_min(*a);
    move_to_top(a, min, 'a');
    push(b, a, 'a');
    min = find_min(*a);
    move_to_top(a, min, 'a');
    push(b, a, 'a');
    sort_three(a);
    push(a, b, 'b');
    push(a, b, 'b');
    if ((*a)->value > (*a)->next->value)
        swap(a, 'a');
}

void sort_large(t_stack **a, t_stack **b)
{
    t_stack *cheapest;

    push_b(a, b);
    sort_three(a);
    while (*b)
    {
        set_target(a, b);
        set_costs(a, b);
        cheapest = find_cheapest(b);
        move_to_top(b, cheapest->value, 'b');
        move_to_top(a, cheapest->target, 'a');
        push(b, a, 'a');
    }
    move_to_top(a, find_min(*a), 'a');
}

void sort(t_stack **a, t_stack **b)
{
    int size = stacklen(a);

    if (size == 2)
        swap(a, 'a');
    else if (size == 3)
        sort_three(a);
    else if (size <= 5)
        sort_five(a, b);
    else
        sort_large(a, b);
}
