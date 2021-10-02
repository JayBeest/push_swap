#include "incl/custom_sort.h"
#include "incl/operations.h"
#include "incl/radix_sort.h"
#include "incl/utils.h"

void	rotate_to_zero(t_ps_stacks *stacks, int amount_of_integers)
{
	int	shift;

	shift = stacks->stack_a[0];
	if (shift <= amount_of_integers / 2)
	{
		while (shift > 0)
		{
			exec_operation(stacks, RRA);
			shift--;
		}
	}
	else
	{
		while (shift < amount_of_integers)
		{
			exec_operation(stacks, RA);
			shift++;
		}
	}
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
	if (stack[0] > stack[1] && stack[1] < stack[2])
		exec_operation(stacks, SA);
}

static void	sort_more_then_three(t_ps_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->amount_of_integers - 3)
	{
		push_num_to_b(stacks, i);
		i++;
	}
	if (!done_already(stacks->stack_a))
		sort_three(stacks);
	while (i > 0)
	{
		exec_operation(stacks, PA);
		i--;
	}
}

void	sort(t_ps_stacks *stacks, int amount_of_integers)
{
	if (only_needs_rotates(stacks->stack_a, amount_of_integers))
		rotate_to_zero(stacks, amount_of_integers);
	else if (amount_of_integers == 3)
		sort_three(stacks);
	else if (amount_of_integers < 56)
		sort_more_then_three(stacks);
	else
		radix_sort(stacks, amount_of_integers);
}
