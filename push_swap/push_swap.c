/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:07:09 by rrault            #+#    #+#             */
/*   Updated: 2023/08/08 15:51:06 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_element(t_data *data, int number, int index)
{
	t_tab	*new_element;
	t_tab	*temp;

	new_element = (t_tab *)malloc(sizeof(t_tab));
	temp = NULL;
	if (!new_element)
		return ;
	new_element->value = number;
	new_element->next = NULL;
	if (index == 1)
		data->stack_a = new_element;
	else
	{
		temp = data->stack_a;
		while (data->stack_a->next)
			data->stack_a = data->stack_a->next;
		data->stack_a->next = new_element;
		data->stack_a = temp;
	}
}

int	ft_free(t_data *data)
{
	t_tab	*current;
	t_tab	*next;

	current = data->stack_a;
	next = NULL;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	current = data->stack_b;
	next = NULL;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	return (0);
}

int	suitemain(t_data *data)
{
	if (check_params(data) == 0)
		return (ft_free(data));
	start_sorting(data);
	ft_free(data);
	return (0);
}

void	print_stacks(t_data *data)
{
	t_tab	*head_a;
	t_tab	*head_b;
	int		index;

	index = 0;
	head_a = data->stack_a;
	head_b = data->stack_b;
	printf("-------------------------------------------------\n");
	printf("|\tStack a :\t|\tStack b :\t|\n");
	while (index < data->total)
	{
		printf("|\t\t");
		if (head_a)
		{
			printf("%d", head_a->value);
			head_a = head_a->next;
		}
		else
			printf("-");
		printf("\t|\t\t");
		if (head_b)
		{
			printf("%d", head_b->value);
			head_b = head_b->next;
		}
		else
			printf("-");
		printf("\t|\n");
		index++;
	}
	printf("-------------------------------------------------\n");
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		i;

	data.stack_a = NULL;
	data.stack_b = NULL;
	i = 0;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (valid_arg(&data, argv[1]) != 1)
			return (write(2, "Error\n", 6));
	}
	else
	{
		data.total = argc - 1;
		while (++i < argc)
		{
			if (check_errors(argv[i], &data) != 0)
				return (ft_free(&data));
			add_element(&data, atoi(argv[i]), i);
		}
	}
	suitemain(&data);
}
