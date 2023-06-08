#include "stack.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct stack *stack_push(struct stack *s, int e)
{
    struct stack *newstack = malloc(sizeof(struct stack));
    if (newstack == NULL)
    {
        return NULL;
    }
    if (s == NULL)
    {
        newstack->data = e;
        newstack->next = NULL;
        return newstack;
    }
    else
    {
        newstack->data = e;
        newstack->next = s;
        return newstack;
    }
}

struct stack *stack_pop(struct stack *s)
{
    if (s == NULL)
    {
        return NULL;
    }
    struct stack *res = s->next;
    free(s);
    return res;
}

int stack_peek(struct stack *s)
{
    return s->data;
}
