/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:46:19 by rpinchas          #+#    #+#             */
/*   Updated: 2023/03/13 17:19:34 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack, char check)
{
	t_list	*tmp;

	tmp = NULL;
	if (!(*stack)->next || !(*stack))
		return ;
	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = *stack;
	*stack = tmp;
	if (check == 'a')
		ft_printf("sa\n");
	if (check == 'b')
		ft_printf("sb\n");
}

void	ft_push(t_list **a, t_list **b, char check)
{
	t_list	*tmp;

	tmp = NULL;
	if (check == 'b' && *a)
	{
		if (*b)
			tmp = *b;
		*b = *a;
		*a = (*a)->next;
		(*b)->next = tmp;
		ft_printf("pb\n");
	}
	if (check == 'a' && *b)
	{
		if (*a)
			tmp = *a;
		*a = *b;
		*b = (*b)->next;
		(*a)->next = tmp;
		ft_printf("pa\n");
	}
	return ;
}

void	ft_rot(t_list **stack, char check)
{
	t_list	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
	if (check == 'a')
		ft_printf("ra\n");
	if (check == 'b')
		ft_printf("rb\n");
}

void	ft_revrot(t_list **stack, char check)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	last = ft_lstlast(*stack);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = *stack;
	*stack = last;
	if (check == 'a')
		ft_printf("rra\n");
	if (check == 'b')
		ft_printf("rrb\n");
}

int	check_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/* Print list to check numbers. 
  for(int i = 0; i < 6; i++)
  {
	ft_printf("%d\n", (*stack)->content);
	*stack = (*stack)->next;
  }
*/
