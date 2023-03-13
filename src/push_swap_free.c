/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:18:40 by rpinchas          #+#    #+#             */
/*   Updated: 2023/03/13 17:51:00 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void *arg, int type)
{
	char	**ar;
	t_list	*list;

	if (type == PTR)
		free_null((char *)arg);
	if (type == ARRAY)
	{
		ar = (char **)arg;
		free_ar(ar);
	}
	if (type == LIST)
	{
		list = (t_list *)arg;
		free_list(&list);
	}
	ft_printf("Error\n");
	exit(0);
}

void	free_list(t_list **lst)
{
	if (*lst)
	{
		free_list(&(*lst)->next);
		free(*lst);
		*lst = NULL;
	}
}

void	*free_ar(char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
	{
		free_null(ar[i]);
		i++;
	}
	free(ar);
	ar = NULL;
	return (NULL);
}

void	*free_null(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}
