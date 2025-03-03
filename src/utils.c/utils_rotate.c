/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:40:30 by mg                #+#    #+#             */
/*   Updated: 2025/02/26 11:43:28 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	reverse(t_stack **top)
{
	t_stack	*ex_top;
	t_stack	*new_bottom;
	t_stack	*ex_bottom;

	ex_bottom = *top;
	new_bottom = *top;
	ex_top = *top;
	while (ex_bottom->next)
		ex_bottom = ex_bottom->next;
	while (new_bottom->next->next)
		new_bottom = new_bottom->next;
	*top = ex_bottom;
	(*top)->next = ex_top;
	new_bottom->next = NULL;
}

static void	rotate(t_stack **top)
{
	t_stack	*ex_top;
	t_stack	*bottom;

	ex_top = *top;
	*top = (*top)->next;
	bottom = *top;
	while (bottom->next)
		bottom = bottom->next;
	ex_top->next = NULL;
	bottom->next = ex_top;
}

void	rotate_move(t_stack **sa, t_stack **sb, char *choice)
{
	if (ft_strcmp(choice, "ra") == 0)
		rotate(sa);
	else if (ft_strcmp(choice, "rb") == 0)
		rotate(sb);
	else if (ft_strcmp(choice, "rr") == 0)
	{
		rotate(sa);
		rotate(sb);
	}
	else if (ft_strcmp(choice, "rra") == 0)
		reverse(sa);
	else if (ft_strcmp(choice, "rrb") == 0)
		reverse(sb);
	else if (ft_strcmp(choice, "rrr") == 0)
	{
		reverse(sa);
		reverse(sb);
	}
	ft_putstr(choice);
	ft_putstr("\n");
}
