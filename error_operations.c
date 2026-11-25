#include "push_swap.h"

void	error(t_stack *stack, char **numbers)
{
	if (numbers)
		free_split(numbers);
	if (stack)
		free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}

