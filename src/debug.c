#include "data.h"
#include "moves.h"
#include "push_swap.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

void imprimir (t_data *data)
{
    t_node  *node;

    node = data->stack_a->first_node;
    printf ("Pila A:");
    while (node != NULL)
    {
        printf("%d ", node->num);
        node = node->next;
    }
    node = data->stack_b->first_node;
    printf ("\nPila B:");
    while (node != NULL)
    {
        printf("%d ", node->num);
        node = node->next;
    }
    printf ("\n");
}

