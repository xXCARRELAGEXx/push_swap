/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:07:58 by rrault            #+#    #+#             */
/*   Updated: 2023/08/04 15:19:51 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_and_reverse(t_data *data)
{
	swap_a(data);
	reverse_rotate_a(data);
}

void	three_numbers(t_data *data)
{
	if ((data->stack_a->value > data->stack_a->next->value)
		&& (data->stack_a->next->value < data->stack_a->next->next->value)
		&& (data->stack_a->value < data->stack_a->next->next->value))
		swap_a(data);
	if ((data->stack_a->value > data->stack_a->next->value)
		&& (data->stack_a->next->value > data->stack_a->next->next->value)
		&& (data->stack_a->value > data->stack_a->next->next->value))
		swap_and_reverse(data);
	if ((data->stack_a->value < data->stack_a->next->value)
		&& (data->stack_a->next->value > data->stack_a->next->next->value)
		&& (data->stack_a->value > data->stack_a->next->next->value))
		reverse_rotate_a(data);
	if ((data->stack_a->value > data->stack_a->next->value)
		&& (data->stack_a->next->value < data->stack_a->next->next->value)
		&& (data->stack_a->value > data->stack_a->next->next->value))
		rotate_a(data);
	if ((data->stack_a->value < data->stack_a->next->value)
		&& (data->stack_a->next->value > data->stack_a->next->next->value)
		&& (data->stack_a->value < data->stack_a->next->next->value))
	{
		swap_a(data);
		rotate_a(data);
	}
}
