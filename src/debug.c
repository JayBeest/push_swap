#include "incl/debug.h"
#include "incl/main.h"
#include "incl/operations.h"
#include "incl/utils.h"

#include <stdio.h>

t_bool	all_same_bits(int *stack, int bit_n, int amount_of_integers)
{
	int		i;

	i = 0;
	while (i < amount_of_integers && stack[i] & (1 << bit_n))
		i++;
	if (i == amount_of_integers)
	{
		printf("bit: %d all 1's\n", bit_n);
		return (TRUE);
	}
	i = 0;
	while (i < amount_of_integers && !(stack[i] & (1 << bit_n)))
		i++;
	if (i == amount_of_integers)
	{
		printf("bit: %d all 0's\n", bit_n);
		return (TRUE);
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

void debug_pb(t_ps_stacks *stacks)
{
	printf("Stack_A(size=%d):\n", stacks->stack_a_size);
	print_stack(stacks->stack_a, stacks->stack_a_size);
	printf("Stack_B(size=%d):\n", stacks->stack_b_size);
	print_stack(stacks->stack_b, stacks->stack_b_size);
	exec_operation(stacks, PB);
	exec_operation(stacks, PB);
	exec_operation(stacks, PB);
	printf("Stack_A(size=%d):\n", stacks->stack_a_size);
	print_stack(stacks->stack_a, stacks->stack_a_size);
	printf("Stack_B(size=%d):\n", stacks->stack_b_size);
	print_stack(stacks->stack_b, stacks->stack_b_size);
}

void debug_ra(t_ps_stacks *stacks)
{
	printf("Stack_A(size=%d):\n", stacks->stack_a_size);
	print_stack(stacks->stack_a, stacks->stack_a_size);
	printf("Stack_B(size=%d):\n", stacks->stack_b_size);
	print_stack(stacks->stack_b, stacks->stack_b_size);
	exec_operation(stacks, RA);
	exec_operation(stacks, RA);
	printf("Stack_A(size=%d):\n", stacks->stack_a_size);
	print_stack(stacks->stack_a, stacks->stack_a_size);
	printf("Stack_B(size=%d):\n", stacks->stack_b_size);
	print_stack(stacks->stack_b, stacks->stack_b_size);
}

void	debug(t_ps_stacks *stacks)
{
//	debug_pb(stacks);
//	debug_ra(stacks);
	printf("Stack_A(size=%d):\n", stacks->stack_a_size);
	print_stack(stacks->stack_a, stacks->stack_a_size);
	printf("Stack_B(size=%d):\n", stacks->stack_b_size);
	print_stack(stacks->stack_b, stacks->stack_b_size);
}
