/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorneli <marvin@codam.nl>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:21:30 by jcorneli          #+#    #+#             */
/*   Updated: 2021/10/08 14:43:00 by jcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <parser.h>
#include <utils.h>

#include <stdio.h>

int	init_stacks(t_ps_stacks *stacks, int argc)
{
	stacks->amount_of_integers = argc - 1;
	stacks->stack_a = malloc((argc - 1) * sizeof(int));
	if (!stacks->stack_a)
		return (0);
	stacks->stack_b = malloc((argc - 1) * sizeof(int));
	if (!stacks->stack_b)
	{
		free (stacks->stack_a);
		return (0);
	}
	stacks->stack_a_size = stacks->amount_of_integers;
	stacks->stack_b_size = 0;
	return (1);
}

void	nums_to_indexes(t_ps_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	while (i < stacks->amount_of_integers)
	{
		j = 0;
		stacks->stack_a[i] = 0;
		while (j < stacks->amount_of_integers)
		{
			if (stacks->stack_b[j] < stacks->stack_b[i])
				stacks->stack_a[i]++;
			j++;
		}
		i++;
	}
	ft_bzero(stacks->stack_b, stacks->amount_of_integers * sizeof(int));
}

t_bool	duplicates(int *stack, int amount_of_integers)
{
	int	i;
	int	j;
	int	duplicates;

	i = 0;
	duplicates = FALSE;
	while (i < amount_of_integers && !duplicates)
	{
		j = 0;
		duplicates = -1;
		while (j < amount_of_integers)
		{
			if (stack[i] == stack[j])
				duplicates++;
			j++;
		}
		i++;
	}
	return (duplicates);
}

t_bool	ft_too_long(char *arg)
{
	if (ft_strlen(arg) > 16)
		return (TRUE);
	return (FALSE);
}

t_bool	parse_arguments(char **argv, t_ps_stacks *stacks)
{
	int		i;
	long	num;

	argv++;
	while (*argv)
	{
		i = 0;
		if (*argv[0] == '-' || *argv[0] == '+')
			i++;
		if (!ft_isdigit((*argv)[i]) || ft_too_long(*argv))
			return (FALSE);
		while ((*argv)[i])
		{
			if (!ft_isdigit((*argv)[i]))
				return (FALSE);
			i++;
		}
		num = ft_atoi(*argv);
		if (num > MAX_INT || num < MIN_INT)
			return (FALSE);
		init_num_to_stack((int)num, stacks->stack_b, \
			stacks->amount_of_integers);
		argv++;
	}
	return (TRUE);
}
