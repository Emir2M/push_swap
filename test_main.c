
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

    printf("Disorder: %.4f\n", compute_disorder(&a));
    adaptive_sort(&a, &b);

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
	int sorted[] = {1, 2, 3, 4, 5};
	int low[] = {2, 1, 3, 4, 5};
	int medium[] = {3, 2, 1, 4, 5};
	int high[] = {5, 4, 3, 2, 1};

	run_test(sorted, 5);
	run_test(low, 5);
	run_test(medium, 5);
	run_test(high, 5);
	return (0);
}