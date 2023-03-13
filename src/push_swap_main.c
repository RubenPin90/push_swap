/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:19:08 by rpinchas          #+#    #+#             */
/*   Updated: 2023/03/13 17:46:48 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**nums;

	stack_b = NULL;
	nums = check_input(argc, argv);
	if (nums)
	{
		stack_a = ar_to_list(argc, nums, SINGLE);
		free_ar(nums);
	}
	else
		stack_a = ar_to_list(argc, argv, MULTI);
	sorting(&stack_a, &stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
}

/*
check_input: Checks if argument input is valid. 
 - if digit or minus (no other input is excepted)
 - if bigger than int_max or int_min
 - if duplicate
save_date: if input is valid, argv is saved into a linked list (struct).
*/
/*
	int i = count_list(stack_a);
	int j = 0;
	t_list *tmp = stack_a;

	if (stack_a != NULL)
	{
	  while (j < i)
	  {
		printf("stack_a [%d]: %d %d\n", j, tmp->content, tmp->index);
		tmp = tmp->next;
		j++;
	  }
	}*/
