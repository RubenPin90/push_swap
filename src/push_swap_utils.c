/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:19:59 by rpinchas          #+#    #+#             */
/*   Updated: 2023/03/13 17:32:19 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

t_list	*ar_to_list(int argc, char **ar, t_bool check)
{
	int		i;
	t_list	*data;

	if (check)
		i = 0;
	else
		i = 1;
	data = NULL;
	while (ar[i])
	{
		ft_lstadd_back(&data, ft_lstnew(ft_atoi(ar[i])));
		i++;
	}
	if (check)
		ft_bubsort(ar, &data);
	else
		ft_bubsort(&ar[1], &data);
	return (data);
}

int	count_list(t_list *stack)
{
	int	i;

	i = 1;
	while (stack && stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

static void	ft_index(t_list **stack, char **ar)
{
	int		i;
	int		len;
	t_list	*tmp;

	i = 0;
	len = count_list(*stack);
	tmp = *stack;
	while (i < len)
	{
		if (tmp && tmp->content == atoi(ar[i]))
		{
			tmp->index = i;
			tmp = tmp->next;
			i = -1;
		}
		i++;
	}
	tmp = *stack;
}

void	ft_bubsort(char **ar, t_list **stack)
{
	int		len;
	int		i;
	char	*tmp;

	len = count_list(*stack);
	while (len-- > 1)
	{
		i = 0;
		while (ar[i] && ar[i + 1])
		{
			if (atoi(ar[i]) > atoi(ar[i + 1]))
			{
				tmp = ar[i + 1];
				ar[i + 1] = ar[i];
				ar[i] = tmp;
			}
			i++;
		}
	}
	ft_index(stack, ar);
}

int	find_min(t_list *stack)
{
	int	j;
	int	i;
	int	min;

	i = 0;
	min = 0;
	j = stack->index;
	while (stack)
	{
		if (j > stack->index)
		{
			j = stack->index;
			min = i;
		}
		stack = stack->next;
		i++;
	}
	return (min);
}
/*
  while(ar[len])
	len++;
  for(int x = 0; x < len; x++)
	ft_printf("ar[%d]: %s\n", x, ar[x]);
  while(ar[len])
	len++;
  t_list *tmp1 = *stack;
  for(int x = 0; x < len; x++) {
	ft_printf("list[%d]: %d %d\n", x, tmp1->content, tmp1->index);
	tmp1 = tmp1->next;
  }
*/
