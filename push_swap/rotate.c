/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:07:47 by rrault            #+#    #+#             */
/*   Updated: 2023/08/08 11:01:56 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_data *data)
{
	t_tab	*temp;
	t_tab	*new_start;

	temp = NULL;
	if (!data->stack_a->next)
		return ;
	if (data->stack_a)
	{
		temp = data->stack_a;
		new_start = temp->next;
		while (data->stack_a->next)
		{
			data->stack_a = data->stack_a->next;
		}
		temp->next = NULL;
		data->stack_a->next = temp;
		data->stack_a = new_start;
		printf("ra\n");
	}
}

void	rotate_b(t_data *data)
{
	t_tab	*temp;
	t_tab	*new_start;

	temp = NULL;
	if (!data->stack_b->next)
		return ;
	if (data->stack_b)
	{
		temp = data->stack_b;
		new_start = temp->next;
		while (data->stack_b->next)
		{
			data->stack_b = data->stack_b->next;
		}
		temp->next = NULL;
		data->stack_b->next = temp;
		data->stack_b = new_start;
		printf("rb\n");
	}
}

void	rotate_both(t_data *data)
{
	rotate_a(data);
	rotate_b(data);
}
