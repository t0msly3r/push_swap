#include "../include/push_swap.h"

static void	write_move(char *move, char ab)
{
	write(1, move, ft_strlen(move));
	write(1, &ab, 1);
	write(1, "\n", 1);
}

void	push(t_stack **src, t_stack **dest, char s)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		index;

	index = 0;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
	temp2 = *dest;
	while (temp2)
	{
		temp2->index = index++;
		temp2 = temp2->next;
	}
	temp2 = *src;
	index = 0;
	while (temp2)
	{
		temp2->index = index++;
		temp2 = temp2->next;
	}
	write_move("p", s);
}

void	swap(t_stack **ab, char s)
{
	t_stack	*temp;

	temp = (*ab)->next;
	(*ab)->index++;
	(*ab)->next = temp->next;
	temp->next = *ab;
	*ab = temp;
	(*ab)->index--;
	write_move("s", s);
}

// first node to last
void	rotate(t_stack **ab, char s)
{
	t_stack	*temp;
	t_stack	*last;
	int		index;

	index = 0;
	if (!*ab || !(*ab)->next)
		return ;
	temp = *ab;
	*ab = (*ab)->next;
	last = *ab;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	temp = *ab;
	while (temp)
	{
		temp->index = index++;
		temp = temp->next;
	}
	write_move("r", s);
}

// last node to first one
void	reverse_rotate(t_stack **ab, char s)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*prev;
	int		index;

	index = 0;
	if (!*ab || !(*ab)->next)
		return ;
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
	while (last)
	{
		last->index = index++;
		last = last->next;
	}
	write_move("rr", s);
}
