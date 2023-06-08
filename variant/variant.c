#include "variant.h"

#include <stdbool.h>
#include <stdio.h>

void variant_display(const struct variant *e)
{
    if (e != NULL)
    {
        if (e->type == TYPE_INT)
        {
            printf("%d", e->value.int_v);
        }
        if (e->type == TYPE_FLOAT)
        {
            printf("%f", e->value.float_v);
        }
        if (e->type == TYPE_CHAR)
        {
            printf("%c", e->value.char_v);
        }
        if (e->type == TYPE_STRING)
        {
            printf("%s", e->value.str_v);
        }
    }
}

bool variant_equal(const struct variant *left, const struct variant *right)
{
    if (left == NULL || right == NULL)
    {
        return true;
    }
    if (left->type == right->type)
    {
        if (left->type == TYPE_INT)
        {
            if (left->value.int_v == right->value.int_v)
            {
                return true;
            }
            return false;
        }
        if (left->type == TYPE_FLOAT)
        {
            if (left->value.float_v == right->value.float_v)
            {
                return true;
            }
            return false;
        }
        if (left->type == TYPE_CHAR)
        {
            if (left->value.char_v == right->value.char_v)
            {
                return true;
            }
            return false;
        }
        if (left->type == TYPE_STRING)
        {
            int count = 0;
            while (left->value.str_v[count] != '\0')
            {
                if (left->value.str_v[count] != right->value.str_v[count])
                {
                    return false;
                }
                count++;
            }
            return true;
        }
    }

    return false;
}

int variant_find(const struct variant *array, size_t len, enum type type,
                 union type_any value)
{
    size_t count = 0;
    while (count < len - 2)
    {
        if (array[count].type == TYPE_INT && type == TYPE_INT)
        {
            if (array[count].value.int_v == value.int_v)
            {
                return count;
            }
        }
        else if (array[count].type == TYPE_FLOAT && type == TYPE_FLOAT)
        {
            if (array[count].value.float_v == value.float_v)
            {
                return count;
            }
        }
        else if (array[count].type == TYPE_CHAR && type == TYPE_CHAR)
        {
            if (array[count].value.char_v == value.char_v)
            {
                return count;
            }
        }
        else if (array[count].type == TYPE_STRING && type == TYPE_STRING)
        {
            if (array[count].value.str_v == value.str_v)
            {
                return count;
            };
        }
        count++;
    }
    return -1;
}

float variant_sum(const struct variant *array, size_t len)
{
    size_t count = 0;
    float sum = 0;
    while (count < len)
    {
        if (array[count].type == TYPE_FLOAT)
        {
            sum += array[count].value.float_v;
        }
        else if (array[count].type == TYPE_INT)
        {
            sum += array[count].value.int_v;
        }
        count++;
    }
    return sum;
}
