/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:50:37 by mg                #+#    #+#             */
/*   Updated: 2025/03/03 11:27:16 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	assign_main_index(t_stack *sa, int size)
{
	t_stack	*a;
	t_stack	*max_address;
	int		max_n;

	while (size--)
	{
		a = sa;
		max_n = INT_MIN;
		max_address = NULL;
		while (a)
		{
			if (a->n == INT_MIN && a->main_index == 0)
				a->main_index = 1;
			else if (a->n > max_n && a->main_index == 0)
			{
				max_n = a->n;
				max_address = a;
				a = sa;
			}
			else
				a = a->next;
		}
		if (max_address)
			max_address->main_index = size + 1;
	}
}

int	stack_size(t_stack *st)
{
	int		size;
	t_stack	*s;

	size = 0;
	s = st;
	while (s)
	{
		size++;
		s = s->next;
	}
	return (size);
}

t_stack	*new_node(int n)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->n = n;
	s->main_index = 0;
	s->position = -1;
	s->where_fit = -1;
	s->mv_a = -1;
	s->mv_b = -1;
	s->next = NULL;
	return (s);
}

void	append_node(t_stack **st, t_stack *new)
{
	t_stack	*s;

	if (!new)
		return ;
	if (!*st)
		*st = new;
	else
	{
		s = *st;
		while (s->next)
			s = s->next;
		s->next = new;
	}
}

t_stack	*create_stack(int ac, char **av)
{
	t_stack		*sa;
	long int	n;
	int			i;
	char		**tmp;

	sa = NULL;
	n = 0;
	i = 0;
	tmp = split_input(ac, av);
	while (tmp[i])
	{
		n = ft_atoi(tmp[i]);
		if (i == 0)
			sa = new_node((int)n);
		else
			append_node(&sa, new_node((int)n));
		i++;
	}
	if (ac == 2)
		ft_free(tmp);
	return (sa);
}
