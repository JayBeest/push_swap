#include <main.h>
#include <libft.h>

#include <stdio.h>

void	init_num_to_stack(int num, int *stack, int amount_of_integers)
{
	static int i;

	if (i < amount_of_integers)
	{
		*(stack + i) = num;
		i++;
	}
	else
		printf("Too many inits?\n");
}

int	duplicates(int *stack, int amount_of_integers)
{
	int	i;
	int j;
	int	duplicates;

	i = 0;
	duplicates = 0;
	while (i < amount_of_integers && !duplicates)
	{
		j = 0;
		duplicates = -1;
		while (j < amount_of_integers)
		{
			printf("stack[i]: %d, stack[j]: %d  (i / j pointers: %p / %p)\n", stack[i], stack[j], &stack[i], &stack[j]);
			if (stack[i] == stack[j])
				duplicates++;
			j++;
		}
		i++;
	}
	return (duplicates);
}

int parse_arguments(char **argv, t_ps_stacks *stacks)
{
	int 		i;
	long long	num;
//	t_bool_err 	bool_err;

	argv++;
	while (*argv)
	{
		i = 0;
		if (*argv[0] == '-' || *argv[0] == '+')
			i++;
		while ((*argv)[i])
		{
			if (!ft_isdigit((*argv)[i]))
				return (printf("Non digit in integer? :(\n"));
			i++;
		}
		num = ft_atoi(*argv);
		if (num > 2147483647 || num < -2147483648)
			return (printf("ONLY integers (check min/max) :(n"));
		init_num_to_stack(num, stacks->stack_b, stacks->amount_of_integers);
		argv++;
		printf("duplicates: %d\n", duplicates(stacks->stack_b, stacks->amount_of_integers));
	}
	return (1);
}

void	nums_to_indexes(t_ps_stacks *stacks)
{
	int	i;
	int	j;
	int smoller_count;

	i = 0;
	while (i < stacks->amount_of_integers)
	{
		j = 0;
		smoller_count = 0;
		while (j < stacks->amount_of_integers)
		{
			if (stacks->stack_b[j] < stacks->stack_b[i])
				smoller_count++;
			j++;
		}
		stacks->stack_a[i] = smoller_count;
		i++;
	}
//	ft_bzero(stacks->stack_b, stacks->amount_of_integers * sizeof(int));
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

int	main(int argc, char **argv)
{
	t_ps_stacks	stacks;
	int	stack_a[argc - 1];
	int	stack_b[argc - 1];

	stacks.stack_a = stack_a;
	stacks.stack_b = stack_b;
	stacks.amount_of_integers = argc - 1;
	stacks.stack_a_size = stacks.amount_of_integers;
	stacks.stack_b_size = 0;
	parse_arguments(argv, &stacks);
	nums_to_indexes(&stacks);
	print_stack(stacks.stack_a, stacks.stack_a_size);
	return (0);
}