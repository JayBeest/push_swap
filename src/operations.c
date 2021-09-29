#include "incl/main.h"
#include "incl/operations.h"
#include "../libft/libft.h"
#include <unistd.h>

static void	pa_operation(t_ps_stacks *stacks)
{
	if (stacks->stack_b_size == 0)
		return ;
	ft_memmove(stacks->stack_a + 1, stacks->stack_a, stacks->stack_a_size * sizeof(int));
	stacks->stack_a[0] = stacks->stack_b[0];
	stacks->stack_a_size++;
	stacks->stack_b_size--;
	ft_memmove(stacks->stack_b, stacks->stack_b + 1, stacks->stack_b_size * sizeof(int));
	write(1, "PA\n", 3);
}

static void	pb_operation(t_ps_stacks *stacks)
{
	if (stacks->stack_a_size == 0)
		return ;
	ft_memmove(stacks->stack_b + 1, stacks->stack_b, stacks->stack_b_size * sizeof(int));
	stacks->stack_b[0] = stacks->stack_a[0];
	stacks->stack_b_size++;
	stacks->stack_a_size--;
	ft_memmove(stacks->stack_a, stacks->stack_a + 1, stacks->stack_a_size * sizeof(int));
	write(1, "PB\n", 3);
}

static void	ra_operation(t_ps_stacks *stacks)
{
	int	temp;

	if (stacks->stack_a_size < 2)
		return ;
	temp = stacks->stack_a[0];
	ft_memmove(stacks->stack_a, stacks->stack_a + 1, (stacks->stack_a_size - 1) * sizeof(int));
	stacks->stack_a[stacks->stack_a_size - 1] = temp;
	write(1, "RA\n", 3);
}

static void	rra_operation(t_ps_stacks *stacks)
{
	int	temp;

	if (stacks->stack_a_size < 2)
		return ;
	temp = stacks->stack_a[stacks->stack_a_size];
	ft_memmove(stacks->stack_a + 1, stacks->stack_a, (stacks->stack_a_size - 1) * sizeof(int));
	stacks->stack_a[0] = temp;
	write(1, "RRA\n", 4);
}

static void	sa_operation(t_ps_stacks *stacks)
{
	int	temp;

	if (stacks->stack_a_size < 2)
		return ;
	temp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[1] = temp;
	write(1, "SA\n", 3);
}

void	exec_operation(t_ps_stacks *stacks, t_operation op)
{
	static const t_operation_ptr fun_ptr[5] = {
			[PA] = pa_operation,
			[PB] = pb_operation,
			[RA] = ra_operation,
			[RRA] = rra_operation,
			[SA] = sa_operation
	};
	fun_ptr[op](stacks);
}
