/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:11:14 by rrault            #+#    #+#             */
/*   Updated: 2023/08/08 10:58:58 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>

typedef struct s_tab	t_tab;

struct	s_tab
{
	int		value;
	int		index;
	t_tab	*next;
};

typedef struct s_data
{
	t_tab	*stack_a;
	t_tab	*stack_b;
	int		total;
	int		min;
	int		max;
	int		parameters;
	int		nbrs;
}		t_data;

void	add_element(t_data *data, int number, int index);
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	swap_both(t_data *data);
void	push_a(t_data *data);
void	push_b(t_data *data);
void	rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	rotate_both(t_data *data);
void	reverse_rotate_a(t_data *data);
void	reverse_rotate_b(t_data *data);
void	reverse_rotate_both(t_data *data);
void	three_numbers(t_data *data);
void	five_numbers(t_data *data);
void	print_stacks(t_data *data);
void	ft_radix(t_data *data);
void	fill_indexes(t_data *data);
void	min_max(t_data *data);
void	start_sorting(t_data *data);
int		ft_free(t_data *data);
int		valid_arg(t_data *data, char *str);
int		check_params(t_data *data);
int		ft_atoi(const char *str);
int		check_errors(char *str, t_data *data);
char	**ft_split(char const *s, t_data *data);
long	ft_strtol(const char *nptr, char **endptr);

#endif
