/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:06:41 by rrault            #+#    #+#             */
/*   Updated: 2023/08/04 14:28:23 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_data *data)
{
	t_tab	*temp;

	if (!data->stack_b)
		return ;
	temp = data->stack_b->next;
	data->stack_b->next = data->stack_a;
	data->stack_a = data->stack_b;
	data->stack_b = temp;
	printf("pa\n");
}

void	push_b(t_data *data)
{
	t_tab	*temp;

	if (!data->stack_a)
		return ;
	temp = data->stack_a->next;
	data->stack_a->next = data->stack_b;
	data->stack_b = data->stack_a;
	data->stack_a = temp;
	printf("pb\n");
}
