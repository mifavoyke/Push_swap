#include "push_swap.h"

const char *skip_whitespace(const char *str)
{
    while (*str == ' ' || *str == '\t' || *str == '\n' 
            || *str == '\v' || *str == '\f' || *str == '\r')
        str++;
    return (str);
}

int handle_sign(const char **str)
{
    int neg = 0;
    if (**str == '-')
    {
        neg = 1;
        (*str)++;
    }
    else if (**str == '+')
        (*str)++;
    return (neg);
}

void calculate_cutoff(int neg, unsigned long *cutoff, int *cutlim)
{
    if (neg)
        *cutoff = -(unsigned long)LONG_MIN;
    else
        *cutoff = LONG_MAX;
    *cutlim = *cutoff % 10;
    *cutoff /= 10;
}

void handle_out_of_range(int neg, unsigned long *acc)
{
    if (neg)
        *acc = LONG_MIN;
    else
        *acc = LONG_MAX;
    errno = ERANGE;
}

void set_endptr(const char **str, char **endptr, int any, const char *original_str)
{
    if (endptr != 0)
    {
        if (any)
            *endptr = (char *)*str;
        else
            *endptr = (char *)original_str;
    }
}
