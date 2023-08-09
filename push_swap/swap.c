/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:08:29 by rrault            #+#    #+#             */
/*   Updated: 2023/08/08 11:02:11 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_data *data)
{
	t_tab	*temp;

	if (data->stack_a->next->next)
	{
		temp = data->stack_a;
		data->stack_a = data->stack_a->next;
		temp->next = data->stack_a->next;
		data->stack_a->next = temp;
		printf("sa\n");
	}
}

void	swap_b(t_data *data)
{
	t_tab	*temp;

	if (data->stack_b->next->next)
	{
		temp = data->stack_b;
		data->stack_b = data->stack_b->next;
		temp->next = data->stack_b->next;
		data->stack_b->next = temp;
		printf("sb\n");
	}
}

void	swap_both(t_data *data)
{
	swap_a(data);
	swap_b(data);
	printf("ss\n");
}
