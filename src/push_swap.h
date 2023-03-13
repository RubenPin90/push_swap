/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:33:01 by rpinchas          #+#    #+#             */
/*   Updated: 2023/03/13 18:00:57 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# define NON 0
# define PTR 1
# define ARRAY 2
# define LIST 3
# define A 'a'
# define B 'b'

typedef enum s_bool
{
	MULTI,
	SINGLE,
}	t_bool;

/*push_swap_check*/
char	**check_input(int argc, char **argv);
int		check_num(int argc, char **argv, t_bool check);
int		check_intmax(int argc, char **input, int i, t_bool check);
int		check_dup(int argc, char **input);

/*push_swap_free*/
void	ft_error(void *arg, int type);
void	*free_ar(char **ar);
void	free_list(t_list **list);
void	*free_null(char *ptr);

/*push_swap_utils*/
t_list	*ar_to_list(int argc, char **nums, t_bool check);
int		count_list(t_list *stack);
void	ft_bubsort(char **ar, t_list **stack);
int		find_min(t_list *stack);

/*push_swap_sort*/
void	sorting(t_list **stack_a, t_list **stack_b);
void	ft_sort_two(t_list **stack);
void	ft_sort_three(t_list **stack);
void	ft_sort_four(t_list **stack_a, t_list **stack_b);
void	ft_sort_five(t_list **stack_a, t_list **stack_b);

/*push_swap_sort_utils*/
void	ft_swap(t_list **stack, char check);
void	ft_push(t_list **a, t_list **b, char check);
void	ft_rot(t_list **stack, char check);
void	ft_revrot(t_list **stack, char check);
int		check_sorted(t_list **stack);

/*push_swap_radix*/
void	ft_radix(t_list **stack_a, t_list **stack_b, int len);
#endif
