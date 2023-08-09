/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:01:56 by rrault            #+#    #+#             */
/*   Updated: 2023/08/04 14:44:09 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_numbers(char *str)
{
	long int	nb;
	char		*ptr;

	errno = 0;
	nb = ft_strtol(str, &ptr);
	if (errno != 0 || ptr == str)
		return (0);
	if (nb < INT_MIN || nb > INT_MAX)
		return (0);
	return (1);
}

static int	arg_error(char *str)
{
	int	i;

	if (!str)
		return (1);
	i = -1;
	if (str[i + 1] == '-')
		i++;
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
	return (0);
}

static int	check_if_exists(char *str, t_data *data)
{
	int		nb;
	t_tab	*temp;

	nb = ft_atoi(str);
	temp = data->stack_a;
	while (data->stack_a)
	{
		if (data->stack_a->value == nb)
			return (1);
		data->stack_a = data->stack_a->next;
	}
	data->stack_a = temp;
	return (0);
}

int	check_errors(char *str, t_data *data)
{
	if (check_numbers(str) == 0 || arg_error(str) == 1
		|| check_if_exists(str, data) == 1 || data->total == 1)
		return (write(2, "Error\n", 6));
	return (0);
}
