#include <rando_bonus.h>
#include <libft.h>
#include <stdlib.h>
#include <stdio.h>
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
		printf("index %d: %d\n", i, stack[i]);
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

t_bool	parse_arguments(char **argv, t_range *range)
{
	int		i;
	int 	j;
	long	num;

	argv++;
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
		num = ft_atoi(*argv);
		argv++;
		if (j == 0)
			range->lower = num;
		else if (j == 1)
			range->upper = num;
		else if (j == 2)
			range->amount_of_integers = num;
		j++;
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	int 	*stack;
	t_range	range;

	if (argc < 2 || !parse_arguments(argv, &range))
		return (1);
	stack = NULL;
	if (!malloc_stack(&stack, range.amount_of_integers))
		return (1);
	random_stack(stack, range.amount_of_integers, range);
	print_stack(stack, range.amount_of_integers);
	free(stack);
	return (0);
}
