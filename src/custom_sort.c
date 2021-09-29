#include "incl/custom_sort.h"
#include "incl/operations.h"

static void	sort_two(t_ps_stacks *stacks)
{
	exec_operation(stacks, RA);
}

static void	sort_three(t_ps_stacks *stacks)
{
	if (stacks->stack_a[0] == 0)
		exec_operation(stacks, RRA);
	else if (stacks->stack_a[0] == 2)
		exec_operation(stacks, RA);
	else if (stacks->stack_a[0] == 1 && stacks->stack_a[1] == 2)
		exec_operation(stacks, RRA);
	if (stacks->stack_a[1] == 0)
		exec_operation(stacks, SA);
}

//static void	sort_four(t_ps_stacks *stacks)
//{
//
//}
//
//static void	sort_five(t_ps_stacks *stacks)
//{
//
//}

void	custom_sort(t_ps_stacks *stacks, int amount_of_integers)
{
	if (amount_of_integers == 2)
		sort_two(stacks);
	else if (amount_of_integers == 3)
		sort_three(stacks);
//	else if (amount_of_integers == 4)
//		sort_four(stacks);
//	else
//		sort_five(stacks);
}
