#include "../include/push_swap.h"

void print_stack(t_stack *a)
{
	t_stack	*temp;

	temp = a;
	while (temp)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}
