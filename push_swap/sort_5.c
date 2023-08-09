/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:08:06 by rrault            #+#    #+#             */
/*   Updated: 2023/08/08 14:36:52 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialisation(t_data *data)
{
	if (data->total == 4)
	{
		push_b(data);
		three_numbers(data);
	}
	else
	{
		push_b(data);
		push_b(data);
		three_numbers(data);
	}
}

int	stack_b_supp(t_data *data)
{
	push_a(data);
	rotate_a(data);
	return (1);
}

int	stack_a_inf(t_data *data)
{
	rotate_a(data);
	return (1);
}

/*void	five_numbers(t_data *data)
{
	int	min_a;
	int	max_a;
	int	i;

	initialisation(data);
	while (data->stack_b)
	{
		min_a = data->stack_a->value;
		max_a = data->stack_a->next->next->value;
		i = 0;
		if (data->stack_b->value < min_a)
			push_a(data);
		else if (data->stack_b->value > max_a)
			i += stack_b_supp(data);
		else
		{
			while (data->stack_b->value > data->stack_a->value)
				i += stack_a_inf(data);
			push_a(data);
			i += 1;
		}
		while (--i > 0)
			reverse_rotate_a(data);
	}
}*/

void	five_numbers(t_data *data)
{
	int	i;

	initialisation(data);
	while (data->stack_b)
	{
		i = 0;
		if (data->stack_b->value == data->max)
		{
			push_a(data);
			rotate_a(data);
		}
		else
		{
			while (data->stack_b->value > data->stack_a->value && ++i > 0)
				rotate_a(data);
			push_a(data);
			i++;
		}
		while (--i > 0)
			reverse_rotate_a(data);
	}
}
