#include "incl/custom_sort.h"
#include "incl/operations.h"

static void	sort_two(t_ps_stacks *stacks)
{
	exec_operation(stacks, RA);
}

static void	sort_three(t_ps_stacks *stacks)
{
	int	*stack;

	stack = stacks->stack_a;
	if (stack[0] < stack[1] && stack[0] < stack[2])
		exec_operation(stacks, RRA);
	else if (stack[0] > stack[1] && stack[0] > stack[2])
		exec_operation(stacks, RA);
	else if (stack[0] < stack[1] && stack[1] > stack[2])
		exec_operation(stacks, RRA);
	if (stack[1] < stack[0] && stack[1] < stack[2])
		exec_operation(stacks, SA);
}

static void	push_num_to_b(t_ps_stacks *stacks, int num)
{
	int			i;
	t_operation	op;

	i = 0;
	while (i < stacks->stack_a_size && stacks->stack_a[i] != num)
		i++;
	if (i > stacks->stack_a_size / 2)
		op = RRA;
	else
		op = RA;
	while (stacks->stack_a[0] != num)
		exec_operation(stacks, op);
	exec_operation(stacks, PB);
}

static void	sort_four(t_ps_stacks *stacks)
{
	push_num_to_b(stacks, 0);
	sort_three(stacks);
	exec_operation(stacks, PA);
}

static void	sort_five(t_ps_stacks *stacks)
{
	push_num_to_b(stacks, 0);
	push_num_to_b(stacks, 1);
	sort_three(stacks);
	exec_operation(stacks, PA);
	exec_operation(stacks, PA);
}

void	custom_sort(t_ps_stacks *stacks, int amount_of_integers)
{
	if (amount_of_integers == 2)
		sort_two(stacks);
	else if (amount_of_integers == 3)
		sort_three(stacks);
	else if (amount_of_integers == 4)
		sort_four(stacks);
	else
		sort_five(stacks);
}
