#include "incl/debug.h"
#include "incl/main.h"
#include "incl/radix.h"
#include "incl/utils.h"

#include <stdio.h>

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
	debug_pb(stacks);
	debug_ra(stacks);
}
