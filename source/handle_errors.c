/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:17:30 by yhusieva          #+#    #+#             */
/*   Updated: 2024/08/12 13:17:32 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*skip_whitespace(char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	return (str);
}

static bool	handle_sign(char **str)
{
	bool	neg;

	neg = false;
	if (**str == '-')
	{
		neg = true;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	return (neg);
}

static long	process_digit(char **str, bool *overflow)
{
	int		digit;
	long	val;

	*overflow = false;
	val = 0;
	while (ft_isdigit(**str))
	{
		digit = **str - '0';
		if (val > (LONG_MAX - digit) / 10)
		{
			*overflow = true;
			return (0);
		}
		val = val * 10 + digit;
		(*str)++;
	}
	return (val);
}

bool	is_integer(char *str)
{
	long	val;
	bool	is_negative;
	bool	overflow;

	val = 0;
	str = skip_whitespace(str);
	is_negative = handle_sign(&str);
	if (*str == '\0' || !(ft_isdigit(*str)))
		return (false);
	val = process_digit(&str, &overflow);
	if (overflow || *str != '\0')
		return (false);
	if (is_negative)
		val = -val;
	if (val < INT_MIN || val > INT_MAX)
		return (false);
	return (true);
}

bool	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

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
