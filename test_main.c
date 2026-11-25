
#include "push_swap.h"
#include <stdio.h>

static void run_test(int *values, int size)
{
    t_stack a = {0};
    t_stack b = {0};
    t_node nodes[500] = {0};
    t_node *cur;
    int i = 0;
    int sorted = 1;

    while (i < size)
    {
        nodes[i].value = values[i];
        if (i > 0)
        {
            nodes[i - 1].next = &nodes[i];
            nodes[i].prev = &nodes[i - 1];
        }
        i++;
    }
    a.head = &nodes[0];
    a.tail = &nodes[size - 1];
    a.size = size;

    medium_sort(&a, &b);

    cur = a.head;
    while (cur && cur->next)
    {
        if (cur->value > cur->next->value)
            sorted = 0;
        cur = cur->next;
    }
    if (a.size != size || b.size != 0)
        sorted = 0;
    printf("\n%d elemanli test: %s\n",
        size, sorted ? "OK" : "FAIL");
}

int main(void)
{
	int values[500];
	int i;
	int j;
	int temp;

	i = 0;
	while (i < 500)
	{
		values[i] = i + 1;
		i++;
	}
	i = 499;
	while (i > 0)
	{
		j = rand() % (i + 1);
		temp = values[i];
		values[i] = values[j];
		values[j] = temp;
		i--;
	}
	run_test(values, 500);
	return (0);
}