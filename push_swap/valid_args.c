/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:36:44 by rrault            #+#    #+#             */
/*   Updated: 2023/08/08 11:01:26 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	free_all(t_data *data, char **split)
{
	free_split(split);
	ft_free(data);
	return (0);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	valid_arg(t_data *data, char *str)
{
	char	**split;
	int		i;

	if (!str || str[0] == 0)
		return (0);
	split = ft_split(str, data);
	i = 0;
	while (i < data->total)
	{
		if (is_valid_number(split[i]))
			add_element(data, ft_atoi(split[i]), i + 1);
		else
			return (free_all(data, split));
		i++;
	}
	free_split(split);
	return (1);
}
