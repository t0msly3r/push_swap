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

void execute_moves(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
    while (cost_a > 0 && cost_b > 0)
    {
        rr(a, b);
        cost_a--;
        cost_b--;
    }
    while (cost_a < 0 && cost_b < 0)
    {
        rrr(a, b);
        cost_a++;
        cost_b++;
    }
    rotate_s(a, &cost_a, 'a');
    rrotate_s(a, &cost_a, 'a');
    rotate_s(b, &cost_b, 'b');
    rrotate_s(b, &cost_b, 'b');
}

// Función para calcular el costo total considerando movimientos combinados
int    calculate_total_cost(int cost_a, int cost_b)
{
    int total;
    int max_cost;
    
    total = 0;
    if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
    {
        if (ft_abs(cost_a) > ft_abs(cost_b))
            max_cost = ft_abs(cost_a);
        else
            max_cost = ft_abs(cost_b);
        total = max_cost;
    }
    else
        total = ft_abs(cost_a) + ft_abs(cost_b);
    return total;
}

// Función optimizada para encontrar el elemento con menor costo total
t_stack *find_cheapest(t_stack **b)
{
    t_stack *temp;
    t_stack *cheapest;
    int     min_cost;
    int total_cost;
    
    temp = *b;
    cheapest = temp;
    while (temp)
    {
        total_cost = calculate_total_cost(temp->cost_a, temp->cost_b);
        
        if (total_cost < min_cost)
        {
            min_cost = total_cost;
            cheapest = temp;
        }
        temp = temp->next;
    }
    
    return cheapest;
}

void sort_large(t_stack **a, t_stack **b)
{
    t_stack *cheapest;
    int min_value;
    int min_idx;
    int size_a;

    min_value = find_min(*a);
    min_idx = get_index(a, min_value);
    size_a = stacklen(a);
    push_b(a, b);
    sort_three(a);
    while (*b)
    {
        set_target(a, b);
        set_costs(a, b);
        cheapest = find_cheapest(b);
        execute_moves(a, b, cheapest->cost_a, cheapest->cost_b);
        push(b, a, 'a');
    }
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
