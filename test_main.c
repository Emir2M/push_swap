
#include "push_swap.h"
#include <stdio.h>

static void run_test(int *values, int size)
{
    t_stack a = {0};
    t_stack b = {0};
    t_node nodes[100] = {0};
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

    simple_sort(&a, &b);

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
    int five[] = {8, 3, 5, 1, 7};
    int ten[] = {10, 3, 8, 1, 6, 9, 2, 7, 5, 4};
    int hundred[100];
    int i = 0;

    run_test(five, 5);
    run_test(ten, 10);
    while (i < 100)
    {
        hundred[i] = 100 - i;
        i++;
    }
    run_test(hundred, 100);
    return (0);
}
