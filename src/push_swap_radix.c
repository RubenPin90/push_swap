/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:01:32 by rpinchas          #+#    #+#             */
/*   Updated: 2023/03/13 17:44:41 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix(t_list **stack_a, t_list **stack_b, int len)
{
	int	i;
	int	j;
	int	num;

	j = 0;
	while (!check_sorted(stack_a))
	{
		i = 0;
		while (i < len)
		{
			num = (*stack_a)->index;
			if ((num >> j) & 1)
				ft_rot(stack_a, A);
			else
				ft_push(stack_a, stack_b, B);
			i++;
		}
		while (*stack_b)
			ft_push(stack_a, stack_b, A);
		j++;
	}
}
