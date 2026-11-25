#include "push_swap.h"

void	reverse_rotate_nodes(t_stack *stack)
{
	t_node	*temp;

	if (stack && stack->head && stack->head->next)
	{
		temp = pop_back(stack);
		add_front(stack, temp);
	}
}

void	rra(t_stack *a)
{
	if (a && a->head && a->head->next)
	{
		reverse_rotate_nodes(a);
		write(1, "rra\n", 4);
		count_op(a, OP_RRA);
	}
}

void	rrb(t_stack *b)
{
	if (b && b->head && b->head->next)
	{
		reverse_rotate_nodes(b);
		write(1, "rrb\n", 4);
		count_op(b, OP_RRB);
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	if ((a && a->head && a->head->next) || (b && b->head && b->head->next))
	{
		reverse_rotate_nodes(a);
		reverse_rotate_nodes(b);
		write(1, "rrr\n", 4);
		if (a && a->config)
			count_op(a, OP_RRR);
		else
			count_op(b, OP_RRR);
	}
}