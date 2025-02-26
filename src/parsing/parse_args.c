/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:02:04 by mg                #+#    #+#             */
/*   Updated: 2025/02/26 10:26:51 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

#include "push_swap.h"

int	check_limit(long num)
{
	if (num > INT_MAX || num < INT_MIN)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

int	check_double(int num, char **args, int i)
{
	i += 1;
	while (args[i])
	{
		if (num == ft_atoi(args[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_is_num(char *av)
{
	int	y;

	y = 0;
	while (av[y])
	{
		if (av[y] == '+' || av[y] == '-')
			y++;
		if (!ft_isdigit((av[y])))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		y++;
	}
	return (1);
}

int	validate_args(char **tmp, char **tmp_bis)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (!check_limit(ft_atoi(tmp[i])) || \
			!check_double(ft_atoi(tmp[i]), tmp, i) || \
			!check_is_num(tmp[i]))
			free_and_exit(tmp_bis);
		i++;
	}
	return (i);
}

int	check_args(int ac, char **av)
{
	int		i;
	char	**tmp;
	char	**tmp_bis;

	tmp_bis = NULL;
	if (ac == 2)
	{
		tmp_bis = ft_split(av[1], ' ');
		tmp = tmp_bis;
	}
	else
		tmp = av + 1;
	i = validate_args(tmp, tmp_bis);
	if (i == 0)
		free_and_exit(tmp_bis);
	if (tmp_bis)
		ft_free(tmp_bis);
	return (0);
}
