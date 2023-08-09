/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:08:16 by rrault            #+#    #+#             */
/*   Updated: 2023/08/08 12:33:36 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_data *data)
{
	while (data->stack_b)
		push_a(data);
}

void	fill_indexes(t_data *data)
{
	int		min;
	int		index;
	t_tab	*tmp;
	t_tab	*head;

	index = 1;
	head = data->stack_a;
	while (index <= data->total)
	{
		min = data->max + 1;
		while (data->stack_a)
		{
			if (data->stack_a->value < min
				&& data->stack_a->value > data->min)
			{
				min = data->stack_a->value;
				tmp = data->stack_a;
			}
			data->stack_a = data->stack_a->next;
		}
		tmp->index = index;
		data->min = tmp->value;
		index++;
		data->stack_a = head;
	}
}

void	min_max(t_data *data)
{
	int		min;
	int		max;
	t_tab	*tmp;

	tmp = data->stack_a;
	min = data->stack_a->value;
	max = data->stack_a->value;
	while (data->stack_a)
	{
		if (data->stack_a->value < min)
			min = data->stack_a->value;
		if (data->stack_a->value > max)
			max = data->stack_a->value;
		data->stack_a = data->stack_a->next;
	}
	data->min = min - 1;
	data->max = max;
	data->stack_a = tmp;
	fill_indexes(data);
}

void	start_sorting(t_data *data)
{
	min_max(data);
	if (data->total == 2)
		swap_a(data);
	else if (data->total == 3)
		three_numbers(data);
	else if (data->total <= 5)
		five_numbers(data);
	else
		ft_radix(data);
}

void	ft_radix(t_data *data)
{
	int		max_bits;
	int		i;
	int		j;

	max_bits = 0;
	while ((data->total - 1) >> max_bits != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < data->total)
		{
			if (((data->stack_a->index >> i) & 1) == 1)
				rotate_a(data);
			else
				push_b(data);
		}
		push_back(data);
	}
}
