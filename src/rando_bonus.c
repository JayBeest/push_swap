/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rando_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorneli <marvin@codam.nl>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:16:33 by jcorneli          #+#    #+#             */
/*   Updated: 2021/10/07 17:16:33 by jcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rando_bonus.h>
#include <libft.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

t_bool	duplicate(int *stack, int amount, int new_num)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		if (stack[i] == new_num)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	print_stack(int *stack, int stack_size)
{
	int	i;

	i = 0;
	while (i < stack_size)
	{
		ft_putnbr_fd(stack[i], 1);
		write(1, " ", 1);
		i++;
	}
}

int	malloc_stack(int **stack, int amount_of_integers)
{
	*stack = (int *)malloc((amount_of_integers) * sizeof(int));
	if (!*stack)
		return (0);
	return (1);
}

t_bool	random_stack(int *stack, int amount, t_range range)
{
	int		i;
	int		new_num;
	int 	dup;
	time_t	seed;

	if (range.upper - range.lower < amount)
		return (FALSE);
	srand((signed) time(&seed));
	i = 0;
	while (i < amount)
	{
		new_num = (rand() % (range.upper - range.lower + 1)) + range.lower;
		dup = 0;
		while (duplicate(stack, amount, new_num))
		{
			dup++;
			new_num = (rand() % (range.upper - range.lower + 1)) + range.lower;
		}
		stack[i] = new_num;
		i++;
	}
	return (TRUE);
}

t_bool	parse_one_arg(char **argv, t_range *range)
{
	int	i;

	i = 0;
	if (*argv[0] == '-' || *argv[0] == '+')
		i++;
	while ((*argv)[i])
	{
		if (!ft_isdigit((*argv)[i]))
			return (FALSE);
		i++;
	}
	range->amount_of_integers = ft_atoi(*argv);
	if (range->amount_of_integers > 200000)
		return (FALSE);
	range->lower = 0;
	range->upper = range->amount_of_integers + 100;
	return (TRUE);
}

t_bool	parse_three_arg(char **argv, t_range *range)
{
	int		i;
	int 	j;

	j = 0;
	while (*argv)
	{
		i = 0;
		if (*argv[0] == '-' || *argv[0] == '+')
			i++;
		while ((*argv)[i])
		{
			if (!ft_isdigit((*argv)[i]))
				return (FALSE);
			i++;
		}
		if (j == 0)
			range->lower = ft_atoi(*argv);
		else if (j == 1)
			range->upper = ft_atoi(*argv);
		else
			range->amount_of_integers = ft_atoi(*argv);
		argv++;
		j++;
	}
	return (TRUE);
}

t_bool	parse(int argc, char **argv, t_range *range)
{
	if (argc == 2)
		return (parse_one_arg(argv + 1, range));
	else if (argc == 4)
		return (parse_three_arg(argv + 1, range));
	else
		return (FALSE);
}

int	main(int argc, char **argv)
{
	int 	*stack;
	t_range	range;

	if (!parse(argc, argv, &range))
		return (1);
	stack = NULL;
	if (!malloc_stack(&stack, range.amount_of_integers))
		return (1);
	if (!random_stack(stack, range.amount_of_integers, range))
		return (1);
	print_stack(stack, range.amount_of_integers);
	free(stack);
	return (0);
}
