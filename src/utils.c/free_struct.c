/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:40:27 by mg                #+#    #+#             */
/*   Updated: 2025/02/26 10:45:39 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	free_stack(t_stack **lst)
{
	t_stack	*c;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		c = (*lst)->next;
		free(*lst);
		*lst = c;
	}
	*lst = NULL;
}

void	ft_free(char **to_free)
{
	int	i;

	i = 0;
	if (!to_free)
		return ;
	while (to_free[i])
		free(to_free[i++]);
	free(to_free);
	to_free = NULL;
}

void	free_and_exit(char **tmp_bis)
{
	if (tmp_bis)
		ft_free(tmp_bis);
	exit(1);
}
