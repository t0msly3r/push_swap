#include "push_swap.h"

void	sort_three(stack **a)
{
	if ((*a)->value > (*a)->next->value && (*a)->value > (*a)->next->next->value)
		rotate(a);
	else if ((*a)->next->value > (*a)->value && (*a)->next->value > (*a)->next->next->value)
		reverse_rotate(a);
	if ((*a)->value > (*a)->next->value)
		swap(a);
}
