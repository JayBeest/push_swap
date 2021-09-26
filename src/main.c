#include <main.h>
#include <libft.h>

#include <stdio.h>

int parse_arguments(char **argv, int stack_a[])
{
	int 		i;
	long long	num;

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
		if (!add_index_to_stack(stack_a, num))
			return (printf("add_stack error?"));
		argv++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	stack_a[argc - 1];
//	int stack_b[argc - 1];

	parse_arguments(argv, stack_a);

	return (0);
}