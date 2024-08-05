#include "push_swap.h"

static unsigned long process_digits(const char **str, unsigned long cutoff, int cutlim, int *any)
{
    unsigned long acc;
    int c;

    acc = 0;
    while ((c = (unsigned char)**str) != '\0')
    {
        if (isdigit(c))
            c -= '0';
        else
            break;
        if (*any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
            *any = -1;
        else
        {
            *any = 1;
            acc = acc * 10 + c;
        }
        (*str)++;
    }
    return (acc);
}

static long ft_strtol_base_10(const char *str, char **endptr, int any)
{
    const char *temp;
    int neg;
    unsigned long cutoff;
    int cutlim;
    unsigned long acc;

    temp = skip_whitespace(str);
    neg = handle_sign(&temp);
    calculate_cutoff(neg, &cutoff, &cutlim);
    acc = process_digits(&temp, cutoff, cutlim, &any);
    if (any < 0)
        handle_out_of_range(neg, &acc);
    else if (neg)
        acc = -acc;
    set_endptr(&temp, endptr, any, str);
    return ((long)acc);
}

bool is_integer(char *str)
{
    char *endptr;
    long val;

    errno = 0;
    val = ft_strtol_base_10(str, &endptr, 0);
    if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN)) || (errno != 0 && val == 0))
        return (false);
    if (endptr == str)
        return (false);
    if (*endptr != '\0')
        return (false);
    if (val < INT_MIN || val > INT_MAX)
        return false;
    return (true);
}

bool has_duplicates(int *arr, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] == arr[j])
                return (true);
            j++;
        }
        i++;
    }
    return (false);
}
