#include "push_swap.h"

void	push(stack **src, stack **dest)
{
	stack	*temp;
	
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
    printf("push\n");
    print_stack(*dest);
}

void	swap(stack **ab)
{
	stack *temp;

	temp = (*ab)->next;
	(*ab)->next = temp->next;
	temp->next = *ab;
	*ab = temp;
    printf("swap\n");
    print_stack(*ab);
}

// first node to last
void	rotate(stack **ab)
{
    stack *temp;
    stack *last;

    if (!*ab || !(*ab)->next)
        return;

    temp = *ab;
    *ab = (*ab)->next;

    last = *ab;
    while (last->next)
        last = last->next;

    last->next = temp;
    temp->next = NULL;
    printf("r\n");
    print_stack(*ab);
}

//last node to first one
void    reverse_rotate(stack **ab)
{
    stack   *temp;
    stack   *last;
    stack   *prev;

    if (!*ab || !(*ab)->next)
        return;
    temp = *ab;
    last = *ab;
    prev = NULL;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = temp;
    *ab = last;
    printf("rr\n");
    print_stack(*ab);
}
