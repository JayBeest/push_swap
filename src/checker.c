#include <main.h>
#include <checker.h>
#include <parser.h>
#include <operations.h>
#include <debug.h>
#include <utils.h>
#include <libft.h>

#include <stdio.h>

t_operation	parse_operation(char *op)
{
	int	len;

	len = ft_strlen(op);
	if (len == 2)
	{
		if (!ft_strncmp(op, "pa", 2))
			return (PA);
		else if (!ft_strncmp(op, "pb", 2))
			return (PB);
		else if (!ft_strncmp(op, "sa", 2))
			return (SA);
		else if (!ft_strncmp(op, "sb", 2))
			return (SB);
		else if (!ft_strncmp(op, "ss", 2))
			return (SS);
		else if (!ft_strncmp(op, "ra", 2))
			return (RA);
		else if (!ft_strncmp(op, "rb", 2))
			return (RB);
		else if (!ft_strncmp(op, "rr", 2))
			return (RR);
	}
	else if (len == 3)
	{
		if (!ft_strncmp(op, "rra", 3))
			return (RRA);
		else if (!ft_strncmp(op, "rrb", 3))
			return (RRB);
		else if (!ft_strncmp(op, "rrr", 3))
			return (RRR);
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	t_ps_stacks	stacks;
	char		*next_operation;
	t_operation	op;

	if (!init_stacks(&stacks, argc))
		return (1);
	if (!parse_arguments(argv, &stacks) || duplicates(stacks.stack_b, stacks.amount_of_integers))
		return (free_stacks(&stacks, 1));
	nums_to_indexes(&stacks);
	print_stack(stacks.stack_a, stacks.stack_a_size);
	while ((next_operation = ft_gnl(1)))
	{
		op = parse_operation(next_operation);
		printf("hier!!!! de op: %d\n", op);
		if (op != ERROR)
			exec_operation(&stacks, op);
		else
			return (free_stacks(&stacks, 1));
	}
	return (free_stacks(&stacks, 0));
}
