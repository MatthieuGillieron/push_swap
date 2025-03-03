/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:50:01 by mg                #+#    #+#             */
/*   Updated: 2025/03/03 10:49:39 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	reverse_both(t_stack **sa, t_stack **sb, int *mv_a, int *mv_b)
{
	while (*mv_a < 0 && *mv_b < 0)
	{
		(*mv_a)++;
		(*mv_b)++;
		rotate_move(sa, sb, "rrr");
	}
}

static void	rotate_both(t_stack **sa, t_stack **sb, int *mv_a, int *mv_b)
{
	while (*mv_a > 0 && *mv_b > 0)
	{
		(*mv_a)--;
		(*mv_b)--;
		rotate_move(sa, sb, "rr");
	}
}

static void	rotate_a(t_stack **sa, int *mv_a)
{
	while (*mv_a)
	{
		if (*mv_a > 0)
		{
			rotate_move(sa, NULL, "ra");
			(*mv_a)--;
		}
		else if (*mv_a < 0)
		{
			rotate_move(sa, NULL, "rra");
			(*mv_a)++;
		}
	}
}

static void	rotate_b(t_stack **sb, int *mv_b)
{
	while (*mv_b)
	{
		if (*mv_b > 0)
		{
			rotate_move(NULL, sb, "rb");
			(*mv_b)--;
		}
		else if (*mv_b < 0)
		{
			rotate_move(NULL, sb, "rrb");
			(*mv_b)++;
		}
	}
}

void	best_move(t_stack **sa, t_stack **sb)
{
	t_stack	*b;
	int		less_moves;
	int		mv_a;
	int		mv_b;

	b = *sb;
	less_moves = INT_MAX;
	while (b)
	{
		if (abs_value(b->mv_a) + abs_value(b->mv_b) < abs_value(less_moves))
		{
			less_moves = abs_value(b->mv_a) + abs_value(b->mv_b);
			mv_a = b->mv_a;
			mv_b = b->mv_b;
		}
		b = b->next;
	}
	if (mv_a < 0 && mv_b < 0)
		reverse_both(sa, sb, &mv_a, &mv_b);
	else if (mv_a > 0 && mv_b > 0)
		rotate_both(sa, sb, &mv_a, &mv_b);
	rotate_a(sa, &mv_a);
	rotate_b(sb, &mv_b);
	swap_move(sa, sb, "pa");
}
