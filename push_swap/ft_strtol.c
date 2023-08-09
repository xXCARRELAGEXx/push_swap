/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:34:35 by rrault            #+#    #+#             */
/*   Updated: 2023/08/01 16:34:36 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	charmap(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (127);
}

long	ft_strtol(const char *nptr, char **endptr)
{
	int		neg;
	long	result;
	char	digit;

	neg = 0;
	result = 0;
	if (*nptr == '-')
		if (*nptr++ == '-')
			neg = 1;
	digit = charmap(*nptr);
	while (digit < 10)
	{
		digit = charmap(*nptr++);
		result = (result * 10) + digit;
		if (result < 0)
		{
			if (endptr)
				*endptr = (char *)nptr;
			return (LONG_MAX + neg);
		}
	}
	if (endptr)
		*endptr = (char *)nptr;
	return (result + (result * -2 * neg));
}
