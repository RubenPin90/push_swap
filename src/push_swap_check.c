/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:50:36 by rpinchas          #+#    #+#             */
/*   Updated: 2023/03/13 17:59:33 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**check_input(int argc, char **argv)
{
	char	**input;
	int		len;

	len = 0;
	if (argc < 2)
		exit(0);
	if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		while (input && input[len])
			len++;
		if (!check_num(len, input, SINGLE))
			ft_error(input, ARRAY);
		if (!check_dup(len, input))
			ft_error(input, ARRAY);
		return (input);
	}
	else
	{
		if (!check_num(argc, argv, MULTI))
			ft_error(NULL, NON);
		if (!check_dup(argc - 1, &argv[1]))
			ft_error(NULL, NON);
	}
	return (NULL);
}

int	check_num(int argc, char **input, t_bool check)
{
	int	i;
	int	j;

	j = 0;
	if (!argc)
		ft_error(NULL, NON);
	if (check)
		i = 0;
	else
		i = 1;
	if (!check_intmax(argc, input, i, check))
		return (0);
	while (i < argc)
	{
		while (input[i][j])
		{
			if (!ft_isdigit(input[i][j]) && input[i][j] != '-')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	check_intmax(int argc, char **input, int i, t_bool check)
{
	char	*tmp;

	while (i < argc)
	{
		tmp = ft_itoa(ft_atoi(input[i]));
		if (!tmp && check)
			ft_error(input, ARRAY);
		if (!tmp && !check)
			ft_error(NULL, NON);
		if (!(ft_strncmp(input[i], tmp, ft_strlen(input[i])) == 0))
		{
			free_null(tmp);
			return (0);
		}
		i++;
		free_null(tmp);
	}
	return (1);
}

int	check_dup(int len, char **input)
{
	int	i;
	int	j;
	int	tmp;

	i = len - 1;
	while (--len)
	{
		j = i;
		while (--j >= 0)
		{
			tmp = ft_strlen(input[len]);
			if (ft_strlen(input[j]) > tmp)
				tmp = ft_strlen(input[j]);
			if ((ft_strncmp(input[len], input[j], tmp)) == 0)
				return (0);
		}
		i--;
	}
	return (1);
}
