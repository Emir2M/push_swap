#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*temp;

	if (!stack)
		return ;
	curr = stack->head;
	while (curr)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
