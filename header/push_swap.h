/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:11:35 by mg                #+#    #+#             */
/*   Updated: 2025/03/03 10:44:56 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>

typedef struct s_stack
{
	int				n;
	int				main_index;
	int				position;
	int				where_fit;
	int				mv_b;
	int				mv_a;
	struct s_stack	*next;
}					t_stack;

	int			check_args(int ac, char **av);
t_stack		*create_stack(int ac, char **av);
char		**split_input(int ac, char **av);
t_stack		*new_node(int n);



void		append_node(t_stack **st, t_stack *new);
int			stack_size(t_stack *st);
void		assign_main_index(t_stack *sa, int size);



int			is_sorted(t_stack *st);
void		swap_move(t_stack **sa, t_stack **sb, char *choice);
void		small_sort(t_stack **st);
void		rotate_move(t_stack **sa, t_stack **sb, char *choice);
void		big_sort(t_stack **sa, t_stack **sb);

void		best_move(t_stack **sa, t_stack **sb);

int			find_lower_pos(t_stack **st);



void		where_fit_in_a(t_stack **sa, t_stack **sb);

void		update_stack_positions(t_stack **st);

void		calculate_moves(t_stack **sa, t_stack **sb);
int			ft_strcmp(char *s1, char *s2);



int			abs_value(int n);



void		ft_putstr(char *s);
void		free_stack(t_stack **st);
void		ft_free(char **to_free);
int			validate_args(char **args, char **tmp);
void		free_and_exit(char **tmp_bis);

#endif