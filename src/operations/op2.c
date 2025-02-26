/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:49:59 by mg                #+#    #+#             */
/*   Updated: 2025/02/26 11:42:58 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"


int	get_lower_position(t_stack **st)
{
	t_stack	*s;
	int		low_index;
	int		low_position;

	s = *st;
	low_index = INT_MAX;
	get_stack_positions(st);
	low_position = s->position;
	while (s)
	{
		if (s->main_index < low_index)
		{
			low_index = s->main_index;
			low_position = s->position;
		}
		s = s->next;
	}
	return (low_position);
}

static void	last_rotates(t_stack **sa)
{
	int	size;
	int	lower_position;

	size = get_stack_size(*sa);
	lower_position = get_lower_position(sa);
	if (lower_position > size / 2)
	{
		while (lower_position++ < size)
			rotate_move(sa, NULL, "rra");
	}
	else
	{
		while (lower_position--)
			rotate_move(sa, NULL, "ra");
	}
}

static void	push_b_save_3(t_stack **sa, t_stack **sb)
{
	int		size;
	int		pushed;
	int		i;

	size = get_stack_size(*sa);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*sa)->main_index <= size / 2)
		{
			swap_move(sa, sb, "pb");
			pushed++;
		}
		else
			rotate_move(sa, NULL, "ra");
		i++;
	}
	while (size - pushed > 3)
	{
		swap_move(sa, sb, "pb");
		pushed++;
	}
	small_sort(sa);
}

void	big_sort(t_stack **sa, t_stack **sb)
{
	push_b_save_3(sa, sb);
	while (*sb)
	{
		where_fit_in_a(sa, sb);
		calculate_moves(sa, sb);
		less_moves_sort(sa, sb);
	}
	if (!is_sorted(*sa))
		last_rotates(sa);
}
