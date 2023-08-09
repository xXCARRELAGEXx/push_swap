/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:33:30 by rrault            #+#    #+#             */
/*   Updated: 2023/08/04 15:03:13 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_params(t_data *data)
{
	t_tab	*temp;

	temp = data->stack_a;
	while (data->stack_a->next)
	{
		if (data->stack_a->value > data->stack_a->next->value)
		{
			data->stack_a = temp;
			return (1);
		}
		data->stack_a = data->stack_a->next;
	}
	data->stack_a = temp;
	return (0);
}
