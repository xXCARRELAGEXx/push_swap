/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:07:36 by rrault            #+#    #+#             */
/*   Updated: 2023/08/08 11:02:04 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_data *data)
{
	t_tab	*temp;
	t_tab	*new_start;

	temp = NULL;
	if (!data->stack_a)
		return ;
	temp = data->stack_a;
	while (data->stack_a->next->next)
		data->stack_a = data->stack_a->next;
	new_start = data->stack_a->next;
	data->stack_a->next = NULL;
	new_start->next = temp;
	data->stack_a = new_start;
	printf("rra\n");
}

void	reverse_rotate_b(t_data *data)
{
	t_tab	*temp;
	t_tab	*new_start;

	temp = NULL;
	if (!data->stack_b)
		return ;
	temp = data->stack_b;
	while (data->stack_b->next->next)
		data->stack_b = data->stack_b->next;
	new_start = data->stack_b->next;
	data->stack_b->next = NULL;
	new_start->next = temp;
	data->stack_b = new_start;
	printf("rrb\n");
}

void	reverse_rotate_both(t_data *data)
{
	reverse_rotate_a(data);
	reverse_rotate_b(data);
	printf("rrr\n");
}
