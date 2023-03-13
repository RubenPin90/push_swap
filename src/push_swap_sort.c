/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:18:53 by rpinchas          #+#    #+#             */
/*   Updated: 2023/03/13 18:17:03 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = count_list(*stack_a);
	if (check_sorted(stack_a) || i < 2)
		return ;
	if (i == 2)
		ft_sort_two(stack_a);
	if (i == 3)
		ft_sort_three(stack_a);
	if (i == 4)
		ft_sort_four(stack_a, stack_b);
	if (i == 5)
		ft_sort_five(stack_a, stack_b);
	else
		ft_radix(stack_a, stack_b, i);
}

void	ft_sort_two(t_list **stack)
{
	if ((*stack)->index > (*stack)->next->index)
		ft_swap(stack, A);
}

void	ft_sort_three(t_list **stack)
{
	int	tmp1;
	int	tmp2;
	int	tmp3;

	tmp1 = (*stack)->index;
	tmp2 = (*stack)->next->index;
	tmp3 = (*stack)->next->next->index;
	if (tmp1 < tmp2 && tmp2 > tmp3 && tmp1 < tmp3)
	{
		ft_swap(stack, A);
		ft_rot(stack, A);
	}
	if (tmp1 < tmp2 && tmp2 > tmp3 && tmp1 > tmp3)
		ft_revrot(stack, A);
	if (tmp1 > tmp2 && tmp2 < tmp3 && tmp1 < tmp3)
		ft_swap(stack, A);
	if (tmp1 > tmp2 && tmp2 < tmp3 && tmp1 > tmp3)
		ft_rot(stack, A);
	if (tmp1 > tmp2 && tmp2 > tmp3 && tmp1 > tmp3)
	{
		ft_swap(stack, A);
		ft_revrot(stack, A);
	}
}

void	ft_sort_four(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = find_min(*stack_a);
	if (min == 1)
		ft_swap(stack_a, A);
	if (min == 3)
		ft_revrot(stack_a, A);
	if (min == 2)
	{
		ft_revrot(stack_a, A);
		ft_revrot(stack_a, A);
	}
	ft_push(stack_a, stack_b, B);
	ft_sort_three(stack_a);
	ft_push(stack_a, stack_b, A);
}

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = find_min(*stack_a);
	if (min == 1)
		ft_swap(stack_a, A);
	if (min == 4)
		ft_revrot(stack_a, A);
	if (min == 3)
	{
		ft_revrot(stack_a, A);
		ft_revrot(stack_a, A);
	}
	if (min == 2)
	{
		ft_rot(stack_a, A);
		ft_rot(stack_a, A);
	}
	ft_push(stack_a, stack_b, B);
	ft_sort_four(stack_a, stack_b);
	ft_push(stack_a, stack_b, A);
}
